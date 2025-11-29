class Solution {
public:
    bool isValidSerialization(string preorder) {
        //Approach-1(Using Stack)
        int slots = 1; // root provides 1 slot
        preorder += ','; // to simplify parsing
        
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] != ',') continue;

            string token = preorder.substr(0, i);
            preorder = preorder.substr(i + 1);
            i = -1;

            // consume a slot
            slots--;
            if (slots < 0) return false;

            // add slots for non-null node
            if (token != "#") slots += 2;
        }
        return slots == 0;
    }
};