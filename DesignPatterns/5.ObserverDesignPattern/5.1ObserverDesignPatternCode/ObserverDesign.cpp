#include<bits/stdc++.h>

using namespace std;

class ISubscriber {
	public:
	virtual void update(const string title) = 0;
	virtual const string getName() const = 0;
	~ISubscriber(){
		cout<<"Destructing ISubscriber class"<<endl;
	}
};



class IChannel {
	public:
	virtual void subscribe(ISubscriber *sub) = 0;
	virtual void unsubscribe(const string name) = 0;
	~IChannel(){
		cout<<"Destructing IChannel class"<<endl;
	}
};

class Channel : public IChannel {
	vector<ISubscriber*> subscribers;
	string name;
	string latestVideo;
	public:
	Channel(const string name){
		this->name = name;
	}
	void subscribe(ISubscriber *sub) override {
		subscribers.push_back(sub);
	}
	
	void unsubscribe(const string name) override{
		for(int i=0;i<subscribers.size();i++){
			if(subscribers[i]->getName() == name){
				subscribers.erase(subscribers.begin()+i);
				cout<<"Unsubscribed "<<name<<endl;
				return;
			}
		}
	}

	void notify(const string title) {
		for(int i=0;i<subscribers.size();i++){
			cout<<"Notifying "<<subscribers[i]->getName() <<endl;
			subscribers[i]->update(title);
		}
	
	}

	void uploadVideo(const string title) {
		this->latestVideo = title;
		cout<<"Uploaded video : "<<title<<endl;
		notify(title);
	}
	
	string getVideo(const string title) {
		return " Fetched data from DB for " + title;
	}
	
};

class Subscriber : public ISubscriber {
	string name;
	class Channel *channel;
	public:
	Subscriber(const string &name, Channel *channel) {
		this->name = name;
		this->channel = channel;
	}
	const string getName() const {
		return name;
	}
	void update(const string title) override;
};

void Subscriber::update(const string title) { // you can write Subscriber::update(const string title) override; in class declaration and define it here
    cout << "Received notification from the channel to : "<< name << endl;
    cout << "Video Title is : " << channel->getVideo(title) << endl;
}

int main() {
	class Channel *ch1 = new Channel("CodeArmy");
	class Subscriber *sub1 = new Subscriber("venkatesh", ch1);
	class Subscriber *sub2 = new Subscriber("arjun", ch1);
	ch1->subscribe(sub1);
	ch1->subscribe(sub2);

	ch1->uploadVideo("Observer Design Pattern in C++");
	// ch1->notify("Hello");

	ch1->unsubscribe("venkatesh");

	cout<<"-----------------------------"<<endl;

	ch1->uploadVideo("Observer Design Pattern in Java");

	return 0;
}