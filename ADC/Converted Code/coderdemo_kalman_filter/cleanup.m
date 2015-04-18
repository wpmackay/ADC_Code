if isempty(currentFigures), currentFigures = []; end;
close(setdiff(findall(0, 'type', 'figure'), currentFigures))
clear mex
delete *.mexw64
rmdir('C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_kalman_filter\codegen','s');
delete C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_kalman_filter\ObjTrack.m
delete C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_kalman_filter\kalman_loop.m
delete C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_kalman_filter\kalmanfilter.m
delete C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_kalman_filter\plot_trajectory.m
delete C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_kalman_filter\position.mat
clear all
load old_workspace
delete old_workspace.mat
delete C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_kalman_filter\cleanup.m
cd C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB
rmdir C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_kalman_filter
