# -*- coding: utf-8 -*-
"""
Created on Mon Jan 27 13:41:30 2020

@author: hella
"""

import os
import serial
import time
import pandas as pd
import plotly
from plotly import graph_objs as go


port     = 'COM8'  # Port connected to Arduino Leonardo
baudrate = 9600    # Transmission rate
filepath = os.getcwd() + "/data/emg_gaehnen.xlsx" 
emg_df   = pd.DataFrame(columns = ['timestamp', 'emg_val'])


#output_file = open(filepath, "w+");
try:
    ser = serial.Serial(port, baudrate, timeout=0)  
except:
    print('Failed to open port.')
else:     
    print('Port opened')
    try:
        start = time.time()
        while (time.time() - start) < 120:
            try:
                emg_val    = ser.readline()
                emg_val    = str(emg_val).split("b'")[1].split("\\r\\n'")[0]
                timestamp  = time.time()
                emg_df = emg_df.append({'timestamp': timestamp, 'emg_val':emg_val}, ignore_index=True)
                time.sleep(0.01)
    #            line = "{}: {} \n".format(str(timestamp), str(val.strip()))
    #            output_file.write(line)                
            except serial.SerialTimeoutException:
                 print('SerialTimeoutException: Data could not be read')
                 time.sleep(0.01)        
    except KeyboardInterrupt:   # kill loop on keyboard interrupt (Strg+C)
        pass
    ser.close()     # close serial port
    emg_df.to_excel(filepath)  
  #  output_file.close()
    
    # Plot data with  plotly
    x = emg_df.timestamp - emg_df.timestamp[0]
    y = emg_df.emg_val
    
    fig = go.Figure(data=go.Scatter(x=x, y=y))
    plotly.offline.plot(fig, filename = r"C:\Users\hella\Desktop\emg.html", auto_open=False)
         
        
