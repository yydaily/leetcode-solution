#include <vector>
#include <map>
#include <algorithm>
class DiscreteTransformation {
public:
    template<typename T>
    std::map<int, int> gen(std::vector<T> a) {
        std::sort(a.begin(), a.end());
        int len = std::unique(a.begin(), a.end()) - a.begin();
        a.resize(len);
        std::map<int, int> m;
        for(int i = 1;i<=a.size();i++) {
            m[a[i-1]] = i;
        }
        return m;
    }
};

DiscreteTransformation dt;