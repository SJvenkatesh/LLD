#include <iostream>
using namespace std;

class Perssitance {

    public:
    virtual void save(string data) = 0;

};

class MySQLDatabase : public Perssitance{  // Low-level module
public:
    void save(string data) {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

class MongoDBDatabase : public Perssitance{  // Low-level module
public:
    void saveToMongo(string data) {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

class UserService {  // High-level module (Tightly coupled)
private:
    class Perssitance *p;

public:
    UserService(Perssitance *p) {
        this->p = p;
    }
    void saveToDB(){
        p->save("Venkatesh");
    }
};

int main() {
    UserService *service = new UserService(new MySQLDatabase());
    service->saveToDB();
}