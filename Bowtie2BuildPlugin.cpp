#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Bowtie2BuildPlugin.h"

void Bowtie2BuildPlugin::input(std::string file) {
 inputfile = file;
}

void Bowtie2BuildPlugin::run() {}

void Bowtie2BuildPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand +=  "bowtie2-build";
myCommand += " -q ";
myCommand += inputfile;
myCommand += " ";
myCommand += outputfile;
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<Bowtie2BuildPlugin> Bowtie2BuildPluginProxy = PluginProxy<Bowtie2BuildPlugin>("Bowtie2Build", PluginManager::getInstance());

