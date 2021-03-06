#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string; using std::vector;
using std::cout; using std::endl;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) { }
    Interval(int s, int e) : start(s), end(e) { }
};

vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> ret;
    std::sort(intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) {
            return a.start < b.start;
    });

    for (const auto &interval : intervals) {
        if (!ret.empty() && interval.start <= ret.back().end) {
            ret.back().end = std::max(interval.end, ret.back().end);
        }
        else {
            ret.push_back(interval);
        }
    }

    return ret;
}

int main() {


    return 0;
}
