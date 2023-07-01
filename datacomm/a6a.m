k = [1:1:30];
f = exp(0.05*k);

fprintf("max: %f\n", max(f));
fprintf("min: %f\n", min(f));
fprintf("sum: %f\n", sum(f));
fprintf("prod: %f\n", prod(f));
fprintf("mean: %f\n", mean(f));
fprintf("var: %f\n", var(f));
fprintf("size: %f\t%f\n", size(f));
fprintf("length: %f\n", length(f));
