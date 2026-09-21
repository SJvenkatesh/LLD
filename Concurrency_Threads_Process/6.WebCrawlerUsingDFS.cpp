#include <bits/stdc++.h>
using namespace std;

class HtmlParser {
public:
    vector<string> getUrls(string url) {
        vector<string> urls;
        if(url == "google.com") {
            urls.push_back("facebook.com");
            urls.push_back("twitter.com");
        } else if(url == "facebook.com") {
            urls.push_back("linkedin.com");
            urls.push_back("google.com");
        }
        return urls;
    }
};

class MultiThreadedWebCrawler {
    unordered_map<string, int> vis;
    mutex mtx;

    public:
     void executeDFS(string url, HtmlParser* htmlParser) {
            unique_lock<mutex> l(mtx);
            if(vis.count(url)) {
                return;
            }
            vis[url] = 1;
            cout<<"Visited: "<<url<<endl;
            l.unlock();
            vector<string> urls = htmlParser->getUrls(url);
            vector<thread> threads;
            for(auto node : urls) {
                threads.push_back(thread(&MultiThreadedWebCrawler::executeDFS, this, node, htmlParser));
            }
            for(auto &t : threads) {
                t.join();
            }
        }
};

int main() {
    MultiThreadedWebCrawler *crawler = new MultiThreadedWebCrawler();
    HtmlParser *htmlParser = new HtmlParser();
    crawler->executeDFS("google.com", htmlParser);
    return 0;
}