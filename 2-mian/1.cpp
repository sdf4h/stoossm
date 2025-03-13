#include <iostream>
#include <vector>
#include <algorithm>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
using namespace std;
using namespace cpr;
using namespace nlohmann;


int main() {
    setlocale(LC_ALL, "ru");
    while (true) {
        // All rules
        Response response1 = Get(Url{ "https://www.dnd5eapi.co/api/rules"});
        if (response1.status_code != 200) {
            cout << response1.error.message << '\n';
            return -1;
        }
        json response_json1 = json::parse(response1.text);

        cout << "Rules";
        cout << "\n------------------\n";
        int count1 = 1;
        for (auto& i : response_json1["results"]) {
            cout << count1++ << ") " << i["name"] << '\n';
        }

        // The Rule
        string input2;
        cout << "\nType the name of the rule: ";
        cin >> input2;

        Response response2 = Get(Url{ "https://www.dnd5eapi.co/api/rules/" + input2 });
        if (response2.status_code != 200) {
            cout << response2.error.message << '\n';
            return -1;
        }
        json response_json2 = json::parse(response2.text);

        cout << "\n" << input2;
        cout << "\n------------------\n";
        int count2 = 1;
        for (auto& i : response_json2["subsections"]) {
            cout << count2++ << ") " << i["name"] << '\n';
        }

        //Subsections
        string input3;
        cout << "\nType the name of the subsection with '-' between the words: ";
        cin >> input3;

        Response response3 = Get(Url{ "https://www.dnd5eapi.co/api/rule-sections/" + input3 });
        if (response3.status_code != 200) {
            cout << response3.error.message << '\n';
            return -1;
        }
        json response_json3 = json::parse(response3.text);

        cout << "\n" << input3;
        cout << "\n------------------\n";
        cout << response_json3["desc"].get<string>() << "\n\n";
    }
}
