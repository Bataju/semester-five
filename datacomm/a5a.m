clc
%for loop addition
x = [2 5; 4 6];
y = [1 5; 6 -2];
z = zeros(2, 2);

for m = 1:2
    for n = 1:2
        z(m, n) = x(m, n)+y(m, n);
        fprintf("%d ", z(m, n));
    end
    fprintf("\n");
end

%while loop subtraction
m = 1;
while m<=2
    n = 1;
    while n<=2
        z(m, n) = x(m, n)-y(m, n);
        fprintf("%d ", z(m, n));
        n= n+1;
    end
    m = m +1;
    fprintf("\n");
end

%without using loops
z = x + y;
fprintf("%d\n", z);