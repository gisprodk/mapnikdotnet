//Created by Univeristy of Maryland CapWIN Project 2009
#include "StdAfx.h"
#include "MapnikStub.h"
#include <stdio.h>



MapnikStub::MapnikStub(void)
	{
	}

MapnikStub::~MapnikStub(void)
	{

	}




void MapnikStub::InitializeXMLMap(CString appDirectory, CString xmlMapFile, int width, int height) {

		std::string sAppDirectory(appDirectory);
		gisDataDirectory = sAppDirectory+"\\data\\gis";

		//Setup project library directory
		nadDirectory = sAppDirectory+"/data/nad";
		nadDirectory = nadDirectory.substr(2,nadDirectory.length()-2);
		for (int i=0;i<nadDirectory.length();i++) {
			if (nadDirectory[i]=='\\') {
				nadDirectory = nadDirectory.replace(i,1,"/");
				}
			}
		mapnik::datasource_cache::instance()->register_datasources(sAppDirectory + "/bin/mapnik/input/"); 
		mapnik::freetype_engine::register_font(sAppDirectory + "/bin/mapnik/fonts/DejaVuSans.ttf");
		mapnik::freetype_engine::register_font(sAppDirectory + "/bin/mapnik/fonts/DejaVuSans-Bold.ttf");
		mapnik::freetype_engine::register_font(sAppDirectory + "/bin/mapnik/fonts/DejaVuSans-BoldOblique.ttf");
		mapnik::freetype_engine::register_font(sAppDirectory + "/bin/mapnik/fonts/DejaVuSansCondensed.ttf");

		std::string sXMLMapFile(xmlMapFile);
		try {
		mapnik::load_map(m,sXMLMapFile);
		} catch (std::exception & eE) {
			std::string errorString = eE.what();
			throw std::exception(eE.what());
		}
	}



	void MapnikStub::RenderToFile(std::string fileName, std::string type, int width, int height,  double lat1,  double long1,  double lat2,  double long2) {

	double scale;

	try {

		//	FILE *out;
		//	out = fopen("c:\\temp\\m.dat","a");
		//	fprintf(out, "%3.10f %3.10f %3.10f %3.10f\r\n", lat1,long1, lat2, long2);
		//	fclose(out);

		m.setWidth(width);
		m.setHeight(height);

		m.zoomToBox(mapnik::Envelope<double>(long1, lat1,  long2, lat2 ));
		//	#print "Scale:" , 1.0/m.scale()


		scale = m.scale();
		mapnik::Image32 buf(m.getWidth(),m.getHeight());
		mapnik::agg_renderer<mapnik::Image32> ren(m,buf);
		ren.apply();
		
		
		mapnik::save_to_file<mapnik::ImageData32>(buf.data(),fileName,type);
		
		
		} catch (std::exception eE) {
			std::string errorString = eE.what();
			throw std::exception(eE.what());
		}

	}



