class PeekingIterator : public Iterator {
private:
    int nextElement;
    bool hasNextElement;

public:
    PeekingIterator(const vector<int>& nums)
        : Iterator(nums) {

        hasNextElement = Iterator::hasNext();

        if (hasNextElement)
            nextElement = Iterator::next();
    }

    int peek() {
        return nextElement;
    }

    int next() {
        int val = nextElement;

        hasNextElement = Iterator::hasNext();

        if (hasNextElement)
            nextElement = Iterator::next();

        return val;
    }

    bool hasNext() const {
        return hasNextElement;
    }
};