import pygame as pg
import numpy as np
import ctypes
from OpenGL.GL import *

class App:
    def __init__(self):
        #initialize pygame
        pg.init()#returns an integer which indicates the number of modules initialized
        #creates a new window, width and height as a tuple, 1st flag - creates an opengl context
        #2nd flag - double buffering system, type of display opengl needs to draw on screen
        pg.display.set_mode((640, 600), pg.OPENGL|pg.DOUBLEBUF)
        #clock object too control the framerate
        self.clock = pg.time.Clock()
        #rgba
        glClearColor(0.2, 0.2, 1, 1)
        self.mainLoop()

    def mainLoop(self):
        running = True
        #game loop that runs infinitely
        while(running):
            #check for events
            for event in pg.event.get():
                if(event.type == pg.QUIT):
                    running = False
            #refresh screen
            #color buffer stores the color values of all pixels on the screen
            #every pixel color is stored in 32 bit uint
            #rgba - so 8 bits per color component
            #instead of 0 to 255 it is 0 to 1 (normalized)
            glClear(GL_COLOR_BUFFER_BIT)
            pg.display.flip()

            #timing- holding the framerate at 60 per secs
            self.clock.tick(60)
        self.quit()

    def quit(self):
        pg.quit()

class Triangle:
    def __init__(self):
        #x y z r g b
        #list of vertices
        #in opengl a vertex is all the data to be stored for a point
        #not just positions, colors textures lightings, etc
        #so here x, y, z and r, g, b values
        self.vertices = {
            -0.5, -0.5, 0.0, 1.0, 0.0, 0.0,#red bottom left
            0.5, -0.5, 0.0, 0.0, 1.0, 0.0,#green bottom right
            0.0, 0.5, 0.0, 0.0, 0.0, 1.0,#blue top mid
        }

        #to ship this vertex data to gpu numpy is used
        #numpys array datatype is built for c style data reading
        #32 bit float is needed by opengl
        #by default numpy will use 64 bit floating point
        self.vertices = np.array(self.vertices, dtype=np.float32)
        self.vertex_count = 3

        #throwing vertices randomly will be ambiguous (is it position first then color data or the other way around)
        #a vertex buffer object by itself is playing dumb data
        #when we add attribute pointers to a vbo, all those data make a vao
        #vertex array objects are the ways to declare vertex data 
        #a vao has a vbo tied up with it
        self.vao = glGenVertexArrays(1)
        glBindVertexArray(self.vao)

        #a vertex buffer object is a basic storage container
        #1 buffer (since it is the first buffer so will be indexed at 0)
        self.vbo = glGenBuffers(1)
        #then we bind that buffer
        #we do this to tell opengl that when we are talking about a gl_array_buffer we are really talking about this buffer - vbo (index 0)
        glBindBuffer(GL_ARRAY_BUFFER, self.vbo)
        #to ship our vertices off to the gpu
        #1 - where to load
        #2 - num of bytes
        #3 - the actual data
        #4 - how we plan to use the data just loaded (there are many usage options)
        #static draw means we'll be setting the data once and using many times
        #dynamic draw means we'll be setting the data and using it multiple times
        glBufferData(GL_ARRAY_BUFFER, self.vertices.nbytes, self.vertices, GL_STATIC_DRAW)

        #now lets complete the declaration by describing the attributes in the vbo
        #first we enable an attribute, then we describe how it's laid out in the vbo
        #1 - attrib 0 is position and attrib 1 is color
        #2 - how many points in each attrib
        #3 - datatype
        #4 - whether opengl will have to perform any task to normalize the numbers
        #5 - the number of bytes the program has to step to get to the next postion or the next color
        #each vertex has 6 numbers and 4 bytes per number (float32 - 32 bits- 4bytes)
        #so stepsize will be 6*4 = 24bytes for both attrib pointers
        #6 - offset - where does the data begin for the first point ( 0 for postion and 12 for color - 3*4)
        #ctypes - just to tell python to take us seriously
        #the function paramter expects a void pointer, a special type of mem addr - ctypes works here
        glEnableVertexArrayAttrib(0)
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, ctypes.c_void_p(0))
        glEnableVertexArrayAttrib(1)
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, ctypes.c_void_p(12))

    def destroy(self):
        #to delete we need to pass a list because the delete function is for lists even when only 1 item is to be deleted
        glDeleteVertexArrays(1, (self.vao,))
        glDeleteBuffers(1, (self.vbo,))


#the entry point
if __name__ == "__main__":
    myApp = App()
    


