#include <bits/stdc++.h>

using namespace std;

tm string_to_tm(const string& str) {
    tm t = {};
    stringstream ss(str);
    ss >> get_time(&t, "%Y-%m-%d %H:%M:%S");
    return t;
}

string tm_to_string(const tm& t) {
    stringstream ss;
    ss << put_time(&t, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

tm add_duration(const tm& t, int duration) {
    time_t time = mktime(const_cast<tm*>(&t)) + duration;
    return *localtime(&time);
}

int main() {
    string day;
    getline(cin, day);
    while (day != "*") {
        getline(cin, day);
    }

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string start_time_str;
        int duration;
        ss >> start_time_str >> duration;

        tm start_time = string_to_tm(start_time_str);
        tm finish_time = add_duration(start_time, duration);

        cout << tm_to_string(finish_time) << endl;
    }

    return 0;
}
