sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) {
            return (a[1] - a[0]) < (b[1] - b[0]);
            // giving "<" sign rather than "-" 
            // see leetcode 1029. Two City Scheduling
            // - is not working 
        });
