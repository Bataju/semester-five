%dy/dt = 2cos(2t)-4y(t)
% Define the function f(t, y) - anonymous function definition
f = @(t, y) 2*cos(2*t)-4*y;

% Define the time interval
tspan = [0 15];

% Define the initial condition
y0 = 2; %y(0)=2

% Solve the ODE
[t, y] = ode23(f, tspan, y0);

% Plot the solution
plot(t, y)
xlabel('t')
ylabel('y')
