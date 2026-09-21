#include <bits/stdc++.h>

using namespace std;

class MoneyHandler {
    protected:
        MoneyHandler *nextHandler;
    public:
        MoneyHandler(){
            nextHandler = NULL;
        }
        void setNextHandler(MoneyHandler *mh){
            this->nextHandler = mh;
        }
        virtual void dispense(int amount) = 0;
};

class ThousandHandler : public MoneyHandler {
    private:
        int numberOfNotes;
    public:
        ThousandHandler(int nn){
            this->numberOfNotes = nn;
        }
        void dispense(int amount) override {
            int notesNeeded = amount /1000;

            if(notesNeeded > numberOfNotes){
                notesNeeded = numberOfNotes;
                numberOfNotes = 0;
            } else {
                numberOfNotes -= notesNeeded;
            }
            if(notesNeeded>0){
                cout << "Dispensing " << notesNeeded << " x ₹1000 notes.\n";
            }

            int remainingAmount = amount - (notesNeeded * 1000);
            if(remainingAmount > 0) {
                if(nextHandler != nullptr) nextHandler->dispense(remainingAmount);
                else {
                    cout << "Remaining amount of " << remainingAmount << " cannot be fulfilled (Insufficinet fund in ATM)\n";
                }
            }
        }
};

class FiveHunderedHandler : public MoneyHandler {
    private:
        int numberOfNotes;
    public:
        FiveHunderedHandler(int nn){
            this->numberOfNotes = nn;
        }
        void dispense(int amount) override {
            int notesNeeded = amount /500;

            if(notesNeeded > numberOfNotes){
                notesNeeded = numberOfNotes;
                numberOfNotes = 0;
            } else {
                numberOfNotes -= notesNeeded;
            }
            if(notesNeeded>0){
                cout << "Dispensing " << notesNeeded << " x ₹500 notes.\n";
            }

            int remainingAmount = amount - (notesNeeded * 500);
            if(remainingAmount > 0) {
                if(nextHandler != nullptr) nextHandler->dispense(remainingAmount);
                else {
                    cout << "Remaining amount of " << remainingAmount << " cannot be fulfilled (Insufficinet fund in ATM)\n";
                }
            }
        }
};

class HunderedHandler : public MoneyHandler {
    private:
        int numberOfNotes;
    public:
        HunderedHandler(int nn){
            this->numberOfNotes = nn;
        }
        void dispense(int amount) override {
            int notesNeeded = amount /100;

            if(notesNeeded > numberOfNotes){
                notesNeeded = numberOfNotes;
                numberOfNotes = 0;
            } else {
                numberOfNotes -= notesNeeded;
            }
            if(notesNeeded>0){
                cout << "Dispensing " << notesNeeded << " x ₹100 notes.\n";
            }

            int remainingAmount = amount - (notesNeeded * 100);
            if(remainingAmount > 0) {
                if(nextHandler != nullptr) nextHandler->dispense(remainingAmount);
                else {
                    cout << "Remaining amount of " << remainingAmount << " cannot be fulfilled (Insufficinet fund in ATM)\n";
                }
            }
        }
};

int main() {
    class MoneyHandler *mth = new ThousandHandler(5);
    class MoneyHandler *mfh = new FiveHunderedHandler(5);
    class MoneyHandler *mhh = new HunderedHandler(2);
    
    mth->setNextHandler(mfh);
    mfh->setNextHandler(mhh);
    int amountHandle = 2700;
    mth->dispense(amountHandle);
    return 0;
}