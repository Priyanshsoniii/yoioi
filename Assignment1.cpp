#include <iostream>
#include <vector>
#include <string>

const double inboxEmailCarbonAmountPerKg = 0.02;
const double sentEmailCarbonAmountPerKg = 0.05;
const double spamEmailCarbonAmountPerKg = 0.03;

enum EmailType { inbox, sent, spam };

struct EmailInfo {
    std::string emailId;
    std::string emailSource;
    double inboxFolderSize;
    double sentFolderSize;
    double spamFolderSize;
};

double calculateCarbonAmountFromSize(double emailFolderSizeInKG, EmailType category) {
    switch (category) {
        case inbox:
            return inboxEmailCarbonAmountPerKg * emailFolderSizeInKG;
        case sent:
            return sentEmailCarbonAmountPerKg * emailFolderSizeInKG;
        case spam:
            return spamEmailCarbonAmountPerKg * emailFolderSizeInKG;
        default:
            return 0;
    }
}

void getCarbonFootprint(const std::string& mailSource, const EmailInfo& emailInfo) {
    if (mailSource == "email") {
        double inboxFolderCarbonAmount = calculateCarbonAmountFromSize(emailInfo.inboxFolderSize, inbox);
        double sentFolderCarbonAmount = calculateCarbonAmountFromSize(emailInfo.sentFolderSize, sent);
        double spamFolderCarbonAmount = calculateCarbonAmountFromSize(emailInfo.spamFolderSize, spam);

        std::cout << mailSource << std::endl;
        std::cout << "emailId : " << emailInfo.emailId << std::endl;
        std::cout << "source: " << emailInfo.emailSource << std::endl;
        std::cout << "inbox : " << inboxFolderCarbonAmount << " KG" << std::endl;
        std::cout << "sent : " << sentFolderCarbonAmount << " KG" << std::endl;
        std::cout << "spam : " << spamFolderCarbonAmount << " KG" << std::endl;
    }
}

int main() {
   
    EmailInfo emailInfo = {
        "priyansh.soni@intimetec.com", 
        "outlook", 
        50.0,  
        5.0,   
        1.0   
    };

    getCarbonFootprint("email", emailInfo);

    return 0;
}
