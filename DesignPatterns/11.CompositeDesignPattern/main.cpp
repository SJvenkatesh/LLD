#include <bits/stdc++.h>

using namespace std;

class FileSystemItem {
    public:
    virtual void OpenAll(int indent = 0) = 0;
    virtual int getSize() = 0;
    virtual string getName() = 0;
};

class File : public FileSystemItem {
    string name;
    int size;
    public:
    File(string name, int size){
        this->name = name;
        this->size = size;
    }
    void OpenAll(int indent = 0) {
        cout<<string(indent, ' ')<<name<<endl;
    }
    int getSize(){
        return size;
    }
    string getName(){
        return name;
    }
};

class Folder : public FileSystemItem {
    string name;
    int size;
    vector<FileSystemItem*> lists;
    public:
    Folder(string name, int size){
        this->name = name;
        this->size = size;
    }
    void addFile(FileSystemItem *fsi){
        lists.push_back(fsi);
    }
    void OpenAll(int indent = 0) {
        cout<<string(indent, ' ')<<name<<" : "<<endl;
        for (auto list : lists){
            list->OpenAll(indent+4);
        }
        cout<<endl;
    }
    int getSize(){
        return size;
    }
    string getName(){
        return name;
    }
};


int main() {
    class FileSystemItem *file1 = new File("File1", 10); 
    class FileSystemItem *file2 = new File("File2", 20); 
    class FileSystemItem *file3 = new File("File3", 30); 

    class Folder *folder1 = new Folder("Folder1", 60); 
    folder1->addFile(file1);
    folder1->addFile(file2);
    folder1->addFile(file3);
    
    folder1->OpenAll(1);

    class FileSystemItem *file4 = new File("File4", 40); 
    class FileSystemItem *file5 = new File("File5", 50); 
    class FileSystemItem *file6 = new File("File6", 50); 

    class Folder *folder2 = new Folder("Folder2", 60); 
    folder2->addFile(file4);
    folder2->addFile(file5);
    folder2->addFile(file6);
    folder1->addFile(folder2);
    folder1->OpenAll(1);
    return 0;
}