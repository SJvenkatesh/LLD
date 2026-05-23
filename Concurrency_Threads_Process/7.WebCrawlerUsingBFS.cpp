#include<bits/stdc++.h>
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
    condition_variable cv;
    HtmlParser* htmlParser;
    queue<string> q;
    public:
    MultiThreadedWebCrawler(HtmlParser* htmlParser) {
        this->htmlParser = htmlParser;
        q.push("google.com");
        vis["google.com"] = 1;
    }
    void executeBFS(string url, HtmlParser* htmlParser) {
        while(true) {
            unique_lock<mutex> l(mtx);
            // cv.wait(l, [this] { return !q.empty(); }); // Wait until queue is not empty this loop for endless loop
            cv.wait_for(l, chrono::seconds(1), [this] { return !q.empty(); }); // Wait until queue is not empty for 1 second
                if(q.empty()) {
                    break; // Exit if queue is empty after waiting
                }

            string node = q.front(); // Get the front URL from the queue
            q.pop();
            cout<<"Visited: "<<node<<endl;
            l.unlock();
            vector<string> urls = htmlParser->getUrls(node);
            for(auto node : urls) {
                unique_lock<mutex> l(mtx);
                if(!vis.count(node)) {
                    vis[node] = 1;
                    q.push(node);
                }
            }
            cv.notify_all();
        }
    }
};

void bfsThread(MultiThreadedWebCrawler *crawler, HtmlParser* htmlParser) {
    crawler->executeBFS("google.com", htmlParser);
}

int main() {
    vector<thread> threads;
    HtmlParser *htmlParser = new HtmlParser();
    MultiThreadedWebCrawler *crawler = new MultiThreadedWebCrawler(htmlParser);
    for(int i = 0; i < 5; i++) {
        threads.push_back(thread(bfsThread, crawler, htmlParser));
    }
    for(auto &t : threads) {
        t.join();
    }
    return 0;
} 