/*********************************************************************
*
* ANSI C Example program:
*    VoltUpdate.c
*
* Example Category:
*    AO
*
* Description:
*    This example demonstrates how to output a single Voltage Update
*    (Sample) to an Analog Output Channel.
*
* Instructions for Running:
*    1. Select the Physical Channel to correspond to where your
*       signal is output on the DAQ device.
*    2. Enter the Minimum and Maximum Voltage Ranges.
*    Note: Use the Acq One Sample example to verify you are
*          generating the correct output on the DAQ device.
*
* Steps:
*    1. Create a task.
*    2. Create an Analog Output Voltage Channel.
*    3. Use the Write function to Output 1 Sample to 1 Channel on the
*       Data Acquisition Card.
*    4. Display an error if any.
*
* I/O Connections Overview:
*    Make sure your signal output terminal matches the Physical
*    Channel I/O Control. For further connection information, refer
*    to your hardware reference manual.
*
*********************************************************************/

/*********************************************************************
* Microsoft Windows Vista User Account Control
* Running certain applications on Microsoft Windows Vista requires
* administrator privileges, because the application name contains keywords
* such as setup, update, or install. To avoid this problem, you must add an
* additional manifest to the application that specifies the privileges
* required to run the application. Some ANSI-C NI-DAQmx examples include
* these keywords. Therefore, these examples are shipped with an additional
* manifest file that you must embed in the example executable. The manifest
* file is named [ExampleName].exe.manifest, where [ExampleName] is the
* NI-provided example name. For information on how to embed the manifest
* file, refer to http://msdn2.microsoft.com/en-us/library/bb756929.aspx.
*********************************************************************/

#include <stdio.h>
#include "NIDAQmx.h"
#include<iostream>
#include<fstream>

#define DAQmxErrChk(functionCall) if( DAQmxFailed(error=(functionCall)) ) goto Error; else


using namespace std;


int main(void)
{
	int			error=0;
	void*	taskHandle=0;
	char		errBuff[2048]={'\0'};
	double     data[1] = {1.0};
	ofstream outlog;
	outlog.open("outLog.txt");

	/*********************************************/
	// DAQmx Configure Coden
	/*********************************************/
	cout<<"set Volt"<<endl;
	
	outlog<<"set Volt"<<endl;

	std::cin>>data[0];	
	
	DAQmxErrChk (DAQmxCreateTask("",&taskHandle));
	printf("task creat success\n");
	outlog<<"task creat success"<<endl;
	DAQmxErrChk (DAQmxCreateAOVoltageChan(taskHandle,"PXI1Slot2/ao0","",-10.0,10.0,DAQmx_Val_Volts,""));
	printf("AOvoltageChan creat success\n");
	outlog<<"AOvoltageChan creat success"<<endl;

	/*********************************************/
	// DAQmx Start Code
	/*********************************************/

	DAQmxErrChk (DAQmxStartTask(taskHandle));
	printf("task start success\n");
	outlog<<"task start success"<<endl;

	/*********************************************/
	// DAQmx Write Code
	/*********************************************/
	// printf("type in Setvolt\n");

	DAQmxErrChk (DAQmxWriteAnalogF64(taskHandle,1,1,10.0,DAQmx_Val_GroupByChannel,data,NULL,NULL));
	printf("analog write success\n");
	outlog<<"analog write success"<<endl;

Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,2048);
	if( taskHandle!=0 ) {
		/*********************************************/
		// DAQmx Stop Code
		/*********************************************/
		DAQmxStopTask(taskHandle);
		DAQmxClearTask(taskHandle);
	}
	if( DAQmxFailed(error) )
		printf("DAQmx Error: %s\n",errBuff);
	printf("End of program, press Enter key to quit\n");
	cout<<"you has set "<< data[0] <<"";
	outlog<<"you has set "<< data[0] <<"";
	
	getchar();


	return 0;
}
