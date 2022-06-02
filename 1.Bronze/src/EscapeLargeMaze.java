class EscapeLargeMaze {
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        HashSet<Long> blockedSet1 = new HashSet<Long>();
        HashSet<Long> blockedSet2 = new HashSet<Long>();
        for(int[] i : blocked) {
            long x = i[0]*1000000+i[1];
            blockedSet1.add(x);
            blockedSet2.add(x);            
        }
        return search(blockedSet1, source, target, source) && search(blockedSet2, target, source, target);
    }
    
    public boolean search(HashSet<Long> blockedSet, int[] source, int[] target, int[] origin) {
        if (source[0]<0 || source[0]>=1000000) return false;
        if (source[1]<0 || source[1]>=1000000) return false;
        long x = source[0]*1000000+source[1];
        if (blockedSet.contains(x)) return false; else blockedSet.add(x);
        if (Math.abs(origin[0]-source[0])+Math.abs(origin[1]-source[1])>200) return true;
        if (source[0] == target[0] && source[1]==target[1]) return true;
        return search(blockedSet, new int[]{source[0]-1, source[1]}, target, origin)
            || search(blockedSet, new int[]{source[0]+1, source[1]}, target, origin)
            || search(blockedSet, new int[]{source[0], source[1]-1}, target, origin)
            || search(blockedSet, new int[]{source[0], source[1]+1}, target, origin);
    }
}