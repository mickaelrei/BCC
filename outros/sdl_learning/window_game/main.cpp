#include <iostream>
#include "src/application/application.hpp"

#include "src/rapidjson/document.h"
#include "src/rapidjson/filereadstream.h"

int main(int argc, char **argv)
{
    // Open the file
	FILE* fp = fopen("config.json", "rb");

	// Read the file into a buffer
	char readBuffer[65536];
	rapidjson::FileReadStream is(fp, readBuffer,
								sizeof(readBuffer));

	// Parse the JSON document
	rapidjson::Document doc;
	doc.ParseStream(is);

	// Close the file
	fclose(fp);

    // Send config to application
    Application app = Application(doc);
    
    app.loop();

    return 0;
}