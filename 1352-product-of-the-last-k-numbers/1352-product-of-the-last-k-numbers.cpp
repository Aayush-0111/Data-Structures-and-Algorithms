class ProductOfNumbers {
private:
    vector<int> numbers;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        numbers.push_back(num);
    }
    
    int getProduct(int k) {
        int n = numbers.size();
        int product{1}, i{n-1};
        while(i >= 0 && k--) product *= numbers[i--];
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */