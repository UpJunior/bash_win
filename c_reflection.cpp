#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

#pragma pack(4)

vector<string> structType;
vector<string> structName;
map<string, int> nameMap;
map<string, void*> typeMap;

#define MEMBER(TYPE,NAME,MORE) TYPE NAME MORE

#define TSTRUCT(NAME,MEMBERS) \
  typedef struct NAME { \
    MEMBERS \
  } NAME; \
  const char* const NAME##_Members = #MEMBERS;

#define PRINT_STRUCT_MEMBERS(NAME) printStructMembers(NAME##_Members)

TSTRUCT(mystruct,
  MEMBER(int,a;,
  MEMBER(int,b;,
  MEMBER(int,c;,
  ))));

void printStructMembers(const char* Members)
{
    int level = 0;
    int lastLevel = 0;
    const char* p;
    const char* pLastType = NULL;
    const char* pLastTypeEnd = NULL;

    for (p = Members; *p; p++)
    {
        if (strstr(p, "MEMBER(") == p)
        {
            p += strlen("MEMBER"); // strlen("MEMBER")
            level++;
            lastLevel = level;
            pLastType = p + 1;
        }
        else if (*p == '(')
        {
            level++;
        }
        else if (*p == ')')
        {
            level--;
        }
        else if (*p == ',')
        {
            if (level == lastLevel)
            {
            if ((pLastType != NULL) && (pLastTypeEnd == NULL))
            {
                pLastTypeEnd = p;
            }
            }
        }
        else if (strstr(p, ";,") == p)
        {
            if ((pLastType != NULL) && (pLastTypeEnd != NULL))
            {
            const char* pp;

            string stringTmp= "";
            for (pp = pLastType; pp < pLastTypeEnd; pp++) {
                stringTmp += *pp;
            }
            structType.push_back(stringTmp);

            stringTmp = "";
            for (pp = pLastTypeEnd + 1; pp < p; pp++) {
                stringTmp += *pp;
            }
            structName.push_back(stringTmp);
            }
            pLastType = pLastTypeEnd = NULL;
        }
    }
}


void EndianTransForm(string &hexString) {
    const int INT_BYTE_LENS = 4 *  2;
    for (int i = 0; i < INT_BYTE_LENS / 2; ++i) {
        char tmpx = hexString[i];
        char tmpy = hexString[i + 1];
        hexString[i] = hexString[INT_BYTE_LENS - i - 2];
        hexString[i + 1] = hexString[INT_BYTE_LENS - i - 1];
        hexString[INT_BYTE_LENS - i - 2] = tmpx;
        hexString[INT_BYTE_LENS - i - 1] = tmpy;
    }
}


int main(int argc, char** argv)
{
   

    nameMap["int"] = 4;
    nameMap["char"] = 1;
    nameMap["float"] = 4;

    PRINT_STRUCT_MEMBERS(mystruct);
 
    mystruct structVar={5, 2, 0};
    mystruct* strucPtr=&structVar;
    unsigned char* charPtr=(unsigned char*)strucPtr;
;

    printf("structure size : %zu bytes\nbytes: ",sizeof(mystruct));
    for(int i=0;i<sizeof(mystruct);i++)
        printf("%02x ",charPtr[i]);
    printf("\n");

    string hexData = "050000000200000000000000";

    printf("struct info print as follow:\n");
    int hexStart = 0;
    for (int i = 0; i < structType.size(); ++i) {
        printf("%s %s [%d], value: ", structType[i].c_str(), structName[i].c_str(), nameMap[structType[i]]);
        int hexNumber;
        string hexString = "";
        for (int j = hexStart; j < hexStart + nameMap[structType[i]] * 2; j+=2) {
            hexString += hexData[j];
            hexString += hexData[j + 1];
        }
        hexStart += nameMap[structType[i]] * 2;
        EndianTransForm(hexString);;
        sscanf(hexString.c_str(), "%x", &hexNumber);
        printf("%d\n",hexNumber);
    }
    return 0;
}
