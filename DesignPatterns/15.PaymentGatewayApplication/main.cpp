#include "./Factory/BankingSystem.h"
#include "./Factory/PaytmBankingSystem.h"
#include "./Factory/RazorPayBankingSystem.h"

#include <bits/stdc++.h>
using namespace std;

struct PaymentRequest {
    string sender;
    string reciever;
    double amount;
    string currency;
    PaymentRequest(const string& sender, const string& reciever, double amt, const string& curr) {
        this->sender = sender;
        this->reciever = reciever;
        this->amount = amt;
        this->currency = curr;
    }
};

class PaymentGateway {
    protected:
        BankingSystem *bankingSystem;
    public:
        PaymentGateway(){
            bankingSystem = NULL;
        }
        ~PaymentGateway(){
            delete bankingSystem;
        }
    
        virtual bool processPayment(PaymentRequest *request) {
                    if (!validatePayment(request)) {
            cout << "[PaymentGateway] Validation failed for " << request->sender << ".\n";
            return false;
            }
            if (!initiatePayment(request)) {
                cout << "[PaymentGateway] Initiation failed for " << request->sender << ".\n";
                return false;
            }
            if (!confirmPayment(request)) {
                cout << "[PaymentGateway] Confirmation failed for " << request->sender << ".\n";
                return false;
            }
        return true;
        }
        virtual bool validatePayment(PaymentRequest *request) = 0;
        virtual bool initiatePayment(PaymentRequest *request) = 0;
        virtual bool confirmPayment(PaymentRequest *request) = 0;

};

class PaytmGateway : public PaymentGateway {
    protected:
        BankingSystem *bankingSystem;
    public:
        PaytmGateway(){
            bankingSystem = new PaytmBankingSystem();
        }
        ~PaytmGateway(){
            delete bankingSystem;
        }
    
    bool validatePayment(PaymentRequest* request) override {
        cout << "[Paytm] Validating payment for " << request->sender << ".\n";

        if (request->amount <= 0 || request->currency != "INR") {
            return false;
        }
        return true;
    }
    bool initiatePayment(PaymentRequest* request) override {
        cout << "[Paytm] Initiating payment of " << request->amount 
                  << " " << request->currency << " for " << request->sender << ".\n";

        bankingSystem->processPayment(request->amount);
        return true;
    }
    bool confirmPayment(PaymentRequest* request) override {
        cout << "[Paytm] Confirming payment for " << request->sender << ".\n";

        // Confirmation always succeeds in this simulation
        return true;
    }
};

class RazorpayGateway : public PaymentGateway {
    protected:
        BankingSystem *bankingSystem;
    public:
        RazorpayGateway(){
            bankingSystem = new RazorpayBankingSystem();
        }
        ~RazorpayGateway(){
            delete bankingSystem;
        }
    
    bool validatePayment(PaymentRequest* request) override {
        cout << "[Razorpay] Validating payment for " << request->sender << ".\n";

        if (request->amount <= 0) {
            return false;
        }
        return true;
    }
    bool initiatePayment(PaymentRequest* request) override {
        cout << "[Razorpay] Initiating payment of " << request->amount 
                  << " " << request->currency << " for " << request->sender << ".\n";

        bankingSystem->processPayment(request->amount);
        return true;
    }
    bool confirmPayment(PaymentRequest* request) override {
        cout << "[Razorpay] Confirming payment for " << request->sender << ".\n";

        // Confirmation always succeeds in this simulation
        return true;
    }
};

class PaymentGatewayProxy : public PaymentGateway {
    protected:
        PaymentGateway *realGateway;
        int retries;
    public:
        PaymentGatewayProxy(PaymentGateway *pg, int retries){
            realGateway = pg;
            this->retries = retries;
        }
        ~PaymentGatewayProxy(){
            delete realGateway;
        }
        bool processPayment(PaymentRequest* request) override {
            bool result = false;
            for (int attempt = 0; attempt < retries; ++attempt) {
                if (attempt > 0) {
                    cout << "[Proxy] Retrying payment (attempt " << (attempt+1)
                            << ") for " << request->sender << ".\n";
                }
                result = realGateway->processPayment(request);
                if (result) break;
            }
            if (!result) {
                cout << "[Proxy] Payment failed after " << (retries)
                        << " attempts for " << request->sender << ".\n";
            }
            return result;
        }
        bool validatePayment(PaymentRequest* request) override {
                return realGateway->validatePayment(request);
        }
        bool initiatePayment(PaymentRequest* request) override {
                return realGateway->initiatePayment(request);
        }
        bool confirmPayment(PaymentRequest* request) override {
                return realGateway->confirmPayment(request);
        }
};

enum class GatewayType {
    PAYTM,
    RAZORPAY
};

class GatewayFactory {
    static class GatewayFactory instance;
    GatewayFactory() {}
    public:
        static GatewayFactory getInstance(){
            return instance;
        }

        PaymentGateway* getGateway(GatewayType type) {
            if(type == GatewayType::PAYTM){
                PaymentGateway* paymentGateway = new PaytmGateway();
                cout<<"[GatewayFactory] creating payment gateway "<<endl;
                return new PaymentGatewayProxy(paymentGateway,3);
            } else {
                  PaymentGateway* paymentGateway = new RazorpayGateway();
                return new PaymentGatewayProxy(paymentGateway,3);
            }
        }

};

GatewayFactory GatewayFactory::instance;


class PaymentServices {
    private:
    static PaymentServices instance;
    PaymentGateway *gateway;

    paymentServices() {
        gateway = NULL;
    }

    ~paymentServices() {
        delete gateway;
    }
    public:

    static PaymentServices getInstance() {
        return instance;
    }

    void setGateway(PaymentGateway *pg) {
        gateway = pg;
    }

}


int main() {

    PaymentGateway *pg = GatewayFactory::getInstance().getGateway(GatewayType::PAYTM);
    class PaymentRequest *req1 = new PaymentRequest("venkatesh", "rahul", 2000, "INR"); 
    pg->processPayment(req1);
    return 0;
}