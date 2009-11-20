//Created by Univeristy of Maryland CapWIN Project 2009
#pragma once


#define BOOST_SPIRIT_THREADSAFE

//This trick keeps freetype.h from crashing due to a generic reserved word useage
#define generic GENERIC

#pragma managed(push, off)
#include <mapnik/map.hpp>
#include <mapnik/datasource_cache.hpp>
#include <mapnik/font_engine_freetype.hpp>
#include <mapnik/agg_renderer.hpp>
#include <mapnik/filter_factory.hpp>
#include <mapnik/color_factory.hpp>
#include <mapnik/image_util.hpp>
#include <mapnik/config_error.hpp>
#include <mapnik/symbolizer.hpp>
#include <mapnik/load_map.hpp>
#pragma managed(pop)
#undef GENERIC


#include <atlstr.h>
#include <string>

class MapnikNative
{
public:
	MapnikNative(void);
	~MapnikNative(void);
    void InitializeXMLMap(CString , CString , int , int );
    void RenderToFile(std::string fileName, std::string type, int width, int height,  double lat1,  double long1,  double lat2,  double long2);
	
private:
	mapnik::Map m;
	std::string gisDataDirectory;
	std::string nadDirectory;
};
