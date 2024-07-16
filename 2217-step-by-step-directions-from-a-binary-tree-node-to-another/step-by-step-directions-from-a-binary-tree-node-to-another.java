class Solution {
    static byte[] path = new byte[200_001];
    int strtLevel = -1;     // Tree level of the start node.
    int destLevel = -1;     // Tree level of the destination node.
    int comnLevel = -1;     // Tree level of the lowest-common-ancestor 
                            //    of the start and destination nodes.
    
    public String getDirections(TreeNode root, int startValue, int destValue) {
        findPaths(root, startValue, destValue, 100_000);
        int answerIdx = comnLevel;
        // Put the "U"'s before the lowest-common-ancestor's index into the 
        // path[] array.  The number of "U"'s is: strtLevel - comnLevel.  
        // Leave the "L" and "R" path info from the lowest-common-ancestor 
        // index through the destination level in path[] array.  Do NOT waste 
        // time copying the "L" and "R" path characters from index comnLevel 
        // through index destLevel in the path[] array.  Leave the "L" and "R" 
        // path in place, and put the correct number of "U"'s before the "L" 
        // and "R" characters.
        for (int i = strtLevel; i > comnLevel; i--)  
            path[--answerIdx] = 'U';
        return new String(path, answerIdx, destLevel - answerIdx);
    }
    
    // Do a recursive depth-first-search for the start and destination nodes.  
    // Build the "L" and "R" path from the root down to the destination node.  
    // Return 0 if didn't find any start or destination node at or below the 
    // passed node.  Return 1 if either the start, destination, or both start 
    // and destination nodes were found at or below the passed node.  If found 
    // both the start node and the destination node, and no lowest-common-ancestor 
    // to the start and destination nodes has been found, then save the passed 
    // node's level as the level of the lowest-common-ancestor.
    private int findPaths(TreeNode node, int strtVal, int destVal, int level) {
        if (node == null)  return 0;
        int result = 0;
        if (node.val == strtVal) {
            strtLevel = level;
            result = 1;
        } else if (node.val == destVal) {
            destLevel = level;
            result = 1;
        }
        int leftFound = 0;
        int rightFound = 0;
        if (comnLevel < 0) {
            if (destLevel < 0)  path[level] = 'L';
            leftFound = findPaths(node.left, strtVal, destVal, level + 1);
            rightFound = 0;
            if (comnLevel < 0) {
                if (destLevel < 0)  path[level] = 'R';
                rightFound = findPaths(node.right, strtVal, destVal, level + 1);
            }
        }
        if (comnLevel < 0 && leftFound + rightFound + result == 2) 
            comnLevel = level;
        return result | leftFound | rightFound;
    }
}