#ifndef BOWTIE2BUILDPLUGIN_H
#define BOWTIE2BUILDPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class Bowtie2BuildPlugin : public Plugin
{
public: 
 std::string toString() {return "Bowtie2Build";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
