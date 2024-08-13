#include <iostream>
#include <string>
using namespace std;

// Adaptee
class JSONAnalyticsTool
{
    string pdata;

public:
    void setJsonData(string jsonData)
    {
        pdata = jsonData;
    }
    void analyseData()
    {
        cout << "Analyzing " << pdata << endl;
    }
};

// interface
class AnalyticsTool
{
public:
    virtual ~AnalyticsTool() {}
    virtual void analyseData() = 0;
};

class XmlToJsonAdapter : public AnalyticsTool
{
    JSONAnalyticsTool tool;

public:
    XmlToJsonAdapter(string xmlData)
    {
        cout << "Converting xml '" << xmlData << " to JSON Data" << endl;
        string newData = xmlData + " in json";
        tool.setJsonData(newData);
    }

    void analyseData()
    {
        tool.analyseData();
    }
};

int main()
{

    AnalyticsTool *tool = new XmlToJsonAdapter("random xml data");
    tool->analyseData();

    return 0;
}