#include <CoreFoundation/CoreFoundation.h>
#include <CoreFoundation/CFDateFormatter.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc <= 1)
    {
        std::cerr<<"no argument provided"<< std::endl;
        std::cout << "please run the program with in the format: setcreationTime -p <path> -t <YYYYMMDDHH>"<< std::endl;
        return 1;
    }
    std::string path;
    std::string createdDate;
    int opt = 0;
    while((opt = getopt(argc, argv, "p:t:")) != -1)
    {
        switch (opt)
        {
            case 'p':
            {
                path = optarg;
                break;
            }
            case 't':
            {
                createdDate = optarg;
                break;
            }
            default:
                std::cerr<<"invalid option provided"<< std::endl;
                std::cout<<"please run the program with in the format: setcreationTime -p <path> -t <YYYYMMDDHH>"<< std::endl;
                break;
                
        }
    }
    if(path.empty() || createdDate.empty())
    {
        std::cerr << "invalid option provided"<< std::endl;
        std::cout << "please run the program with in the format: setcreationTime -p <path> -t <YYYYMMDDHH>"<< std::endl;
        return 1;
    }
    Boolean isDirectory = FALSE;
    size_t filenameLen = std::strlen(path.c_str());
    CFURLRef url = CFURLCreateFromFileSystemRepresentation(kCFAllocatorDefault, (const UInt8*)path.c_str(), filenameLen, isDirectory);
    CFStringRef cfStrDate = CFStringCreateWithCString(kCFAllocatorDefault,
                                                        createdDate.c_str(), kCFStringEncodingMacRoman);
    CFDateFormatterRef dateFormatter = CFDateFormatterCreate(kCFAllocatorDefault, CFLocaleCopyCurrent(), kCFDateFormatterNoStyle, kCFDateFormatterNoStyle);
    CFDateFormatterSetFormat(dateFormatter, CFSTR("yyyyMMddHH"));
    CFDateRef cfDate = CFDateFormatterCreateDateFromString(kCFAllocatorDefault, dateFormatter, cfStrDate, NULL);
    if(!cfDate)
    {
        CFRelease(cfStrDate);
        CFRelease(dateFormatter);
        std::cerr << " can't create a date with provided date string, please review the date parameter"<< std::endl;
    }
    CFRelease(cfStrDate);
    CFRelease(dateFormatter);
    CFErrorRef error = 0;
    // set creation Date;
    if(!CFURLSetResourcePropertyForKey(url, kCFURLCreationDateKey, cfDate, &error))
    {
        std::cerr << " can't set creation date error: "<< error << std::endl;
        CFRelease(cfDate);
        CFRelease(url);
        return 1;
    }
    std::cout<<" creation date set succesfull to "<< createdDate << std::endl;
    CFRelease(cfDate);
    CFRelease(url);
    return 0;
}
