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
myCommand +=  "bowtie2-build ";
std::ifstream infile(inputfile, std::ios::in);
std::string onefile; 
   std::vector<std::string> myfiles;
   while (!infile.eof()){
   getline(infile, onefile);
   if (onefile.length() != 0) {
	   if (onefile[0] != '/')
   myfiles.push_back(std::string(PluginManager::prefix())+std::string(onefile));
	   else
		   myfiles.push_back(std::string(onefile));
   }

}

for (int i = 0; i < myfiles.size(); i++) {
   myCommand += myfiles[i];
   if (i != myfiles.size()-1)
	   myCommand += ",";
}
//myCommand += " -q ";
//myCommand += inputfile;
myCommand += " ";
myCommand += outputfile;
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<Bowtie2BuildPlugin> Bowtie2BuildPluginProxy = PluginProxy<Bowtie2BuildPlugin>("Bowtie2Build", PluginManager::getInstance());

