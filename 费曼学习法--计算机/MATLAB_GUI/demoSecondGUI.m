function varargout = demoSecondGUI(varargin)
% DEMOSECONDGUI MATLAB code for demoSecondGUI.fig
%      DEMOSECONDGUI, by itself, creates a new DEMOSECONDGUI or raises the existing
%      singleton*.
%
%      H = DEMOSECONDGUI returns the handle to a new DEMOSECONDGUI or the handle to
%      the existing singleton*.
%
%      DEMOSECONDGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in DEMOSECONDGUI.M with the given input arguments.
%
%      DEMOSECONDGUI('Property','Value',...) creates a new DEMOSECONDGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before demoSecondGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to demoSecondGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help demoSecondGUI

% Last Modified by GUIDE v2.5 10-Feb-2022 13:37:49

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @demoSecondGUI_OpeningFcn, ...
                   'gui_OutputFcn',  @demoSecondGUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before demoSecondGUI is made visible.
function demoSecondGUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to demoSecondGUI (see VARARGIN)

% Choose default command line output for demoSecondGUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes demoSecondGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = demoSecondGUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function editFirst_Callback(hObject, eventdata, handles)
% hObject    handle to editFirst (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editFirst as text
%        str2double(get(hObject,'String')) returns contents of editFirst as a double


% --- Executes during object creation, after setting all properties.
function editFirst_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editFirst (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editSecond_Callback(hObject, eventdata, handles)
% hObject    handle to editSecond (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editSecond as text
%        str2double(get(hObject,'String')) returns contents of editSecond as a double


% --- Executes during object creation, after setting all properties.
function editSecond_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editSecond (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in OKButton.
function OKButton_Callback(hObject, eventdata, handles)
% hObject    handle to OKButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% 1) ????????????1??2????????????????????????????

data1 = get(handles.editFirst, 'string') %editFirst????????????????????tag
data2 = get(handles.editSecond, 'string') %editSecond????????????????????tag

floatData1 = str2num(data1);
floatData2 = str2num(data2);

%row,col ????floatData??????????
[row1, col1 ]= size(floatData1);
[row2, col2 ]= size(floatData2);

% ????????????????12 23??????????????????????????str2num????????????????????????1
% ??????????????????????????str2num????????????[]??????????isempty????????????
if (col1~=1 || col2 ~=1 || isempty(floatData1)...
    || isempty(floatData2))
    
    f1 = msgbox('??????????????????????????','error' ,'error');
else
    f2 = msgbox('??????????');
    
    % 2) ????????????????????????
    result = floatData1*floatData2
    
    % ??????????readtable??????????????????????????????????????????????????????????2??1??
    result = [result;result];
    
    % 3) ????????????????excel??
    xlswrite('result.xls', result);
    
    % 4) ??demoFirstGUi????mainTable????????
    
    % findobj??????????demoFirstGUI??tag????mainTable????????????????????????
    h = findobj(demoFirstGUI, 'tag', 'mainTable');
    
    % readtable ??????excel??????????
    resultFromExcel = readtable('result.xls');
    
    % table2cell??????table??????????????cell??????uitable??????????table????????    
    cellData = table2cell(resultFromExcel);
        
    %set??????uitable????????
    set(h, 'data', cellData);
end



% --- Executes on button press in shutDownButton.
function shutDownButton_Callback(hObject, eventdata, handles)
% hObject    handle to shutDownButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% ??copyfile??result.xls??????D????????
status = copyfile('result.xls', 'D:\');

if status == 1
    f1 = msgbox('??????????');
    
    % ????????GUI
    close(demoSecondGUI);
else
    f2 = msgbox('??????????','error', 'error');
end
