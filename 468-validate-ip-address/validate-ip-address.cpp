class Solution {
public:
    bool isIPv4(string IP) {
        stringstream ss(IP);
        string part;
        int count = 0;

        while (getline(ss, part, '.')) {

            if (part.empty() || part.size() > 3)
                return false;

            if (part.size() > 1 && part[0] == '0')
                return false;

            for (char c : part) {
                if (!isdigit(c))
                    return false;
            }

            int num = stoi(part);

            if (num < 0 || num > 255)
                return false;

            count++;
        }

        return count == 4 && IP.back() != '.';
    }

    bool isIPv6(string IP) {
        stringstream ss(IP);
        string part;
        int count = 0;

        while (getline(ss, part, ':')) {

            if (part.empty() || part.size() > 4)
                return false;

            for (char c : part) {
                if (!isxdigit(c))
                    return false;
            }

            count++;
        }

        return count == 8 && IP.back() != ':';
    }

    string validIPAddress(string queryIP) {

        if (count(queryIP.begin(),
                  queryIP.end(), '.') == 3) {

            return isIPv4(queryIP)
                   ? "IPv4"
                   : "Neither";
        }

        if (count(queryIP.begin(),
                  queryIP.end(), ':') == 7) {

            return isIPv6(queryIP)
                   ? "IPv6"
                   : "Neither";
        }

        return "Neither";
    }
};