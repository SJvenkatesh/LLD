#include <bits/stdc++.h>

using namespace std;

class IReports {
    public:
        virtual string getJSONData(string data) = 0;
};

class XMLDataProvider {
    public:
    string getXMLData(string data){
        return " XML "+data;
    }
};

class XMLDataProviderAdapter : public IReports {
    class XMLDataProvider *xdp;
    public:
        XMLDataProviderAdapter(class XMLDataProvider *xdp) {
            this->xdp = xdp;
        }
        string getJSONData(string data) {
            return " JSON " + xdp->getXMLData(data);
        }
};


class Client {
    public:
    string getReportData(class IReports *ir, string data){
        return "Processed Report " + ir->getJSONData(data);      
    }
};

int main() {
    class XMLDataProvider *xdp = new XMLDataProvider();
    class IReports *ir = new XMLDataProviderAdapter(xdp);
    class Client *c = new Client();
    cout<<" Output : "<< c->getReportData(ir, "venkatesh")<<endl;
    return 0;
}