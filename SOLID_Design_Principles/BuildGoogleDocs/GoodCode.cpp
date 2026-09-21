#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class DocumentElement {
    public:
    virtual string render() = 0;
};



class TextElement : public DocumentElement {
    private:
        string text;
    public:
    TextElement(string text) {
        this->text = text;
    }
    string render() override {
        return text;
    }
};

class ImageElement : public DocumentElement {
    private:
    	string img;
    public:
    ImageElement(string img) {
    	this->img = img;
    }
    string render() override {
    	return "Image : ["+img+"] ";
    }
};

class Document {
	private: 
	vector<DocumentElement*> de;
	public:
	
	void render(){	 
		for(auto ele : de){
			cout<<ele->render()<<endl;
		}
	}
	
	void addElement(DocumentElement* ele) {
		de.push_back(ele);
	}
};


class Persistance {
    public:
	virtual void save(Document *doc) = 0;
};


class SaveToFile : public Persistance {
    public:
	void save(Document *doc) override {
		cout<<"Save to File"<<endl;
	}
};

class SaveToDB : public Persistance {
    public:
	void save(Document *doc) override {
		cout<<"Save to DB"<<endl;
	}
};


class DocumentEditor {
private:
	Document *doc;
	Persistance *p;	
public:
    DocumentEditor(string saveAs) {
    	this->doc = new Document(); 
    	if(saveAs == "FILE"){
    		this->p = new  SaveToFile();
    	} else {
    		this->p = new  SaveToDB();
    	}
    }
	
    // Adds text as a plain string
    void addText(string text) {
    	class DocumentElement *TE = new TextElement(text);
        doc->addElement(TE);
    }

    // Adds an image represented by its file path
    void addImage(string imagePath) {
    	class DocumentElement *IE = new ImageElement(imagePath);
        doc->addElement(IE);
    }

    // Renders the document by checking the type of each element at runtime
    void renderDocument() {
	    doc->render();
    }

    void saveToFile() {
	p->save(doc);
    }
};

int main() {
    DocumentEditor *editor = new DocumentEditor("FILE");
    editor->addText("Hello, world!");
    editor->addImage("picture.jpg");
    editor->addText("This is a document editor.");

    editor->renderDocument();

    editor->saveToFile();
    
    return 0;
}