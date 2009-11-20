//Created by Univeristy of Maryland CapWIN Project 2009
#include "StdAfx.h"
#include "MapnikWrapper.h"

#include <math.h>

using namespace org::capwin::gis::mapnik;
using namespace System;



int MapnikWrapper::InitializeXMLLayer(String ^ appDirectory, String ^ mapXMLFile) {

	try {
		MapnikWrapper::myLog->Debug("Initializing map with xml file");
		CString cAppDirectory(appDirectory);
		CString cxmlFile(mapXMLFile);
		if (ms !=NULL) {
			delete ms;
			}
		ms = new	MapnikStub();
		ms->InitializeXMLMap(cAppDirectory, cxmlFile,700,700);
		} catch (std::exception eE) {
			System::String ^ s;
			s = gcnew String(eE.what());
			MapnikWrapper::myLog->Error(s);
			throw gcnew ApplicationException(s);
		}
	
	
	
	return 0;
	}




int MapnikWrapper::RenderToFile(String ^ fileName,String ^type, int width, int height,  double lat1,  double  long1,  double lat2,  double  long2) {
	CString cFileName(fileName);
	std::string sFileName(cFileName);
	
	CString cType(type);
	std::string sType(cType);
	
	try {
		MapnikWrapper::myLog->Debug("Starting Render:" + fileName);

	ms->RenderToFile(sFileName, sType, width,height, lat1,long1,lat2,long2);
			} catch (std::exception eE) {
			System::String ^ s;
			s = gcnew String(eE.what());
			MapnikWrapper::myLog->Error(s);
			throw gcnew ApplicationException(s);
		}
	return 0;
	}