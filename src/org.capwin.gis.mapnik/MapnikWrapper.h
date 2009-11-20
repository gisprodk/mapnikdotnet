//Created by Univeristy of Maryland CapWIN Project 2009
#include "MapnikStub.h"

#include <vcclr.h>
#include <atlstr.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace org {
	namespace capwin {
		namespace gis {
		namespace  mapnik 
		{

	/// <summary>
	/// Summary for MapnikWrapper
	/// </summary>
		public ref class MapnikWrapper 
	{
	public:
		MapnikStub *ms;
		int MapnikWrapper::RenderToFile(String ^ fileName,String ^type, int width, int height, double  lat1,  double  long1,  double  lat2,  double  long2);
		int MapnikWrapper::InitializeXMLLayer(String ^ appDirectory, String ^ mapXMLFile);
		MapnikWrapper(void)
		{
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MapnikWrapper()
		{
			if (ms !=NULL) {
				delete ms;
			}
		
		}

	private:
		static log4net::ILog ^ myLog = log4net::LogManager::GetLogger(System::Reflection::MethodBase::GetCurrentMethod()->DeclaringType);


	};
		}}}}
