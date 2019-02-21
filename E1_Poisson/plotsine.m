%#ok<*NOPTS>

%% Import Data
filename = 'output.out' 
[r,x,y] = dat_import(filename);

%% Plot RAW Data
figure
pcolor(x,y,r)
colormap(gray(20))
xlabel 'x'
ylabel 'y'
title 'RAW Data'

%% Error and Convergence