class Solution:
    def findRotateSteps(self, ring, key):
        ltr_indexes = {'#' : [0]}
        # print(ltr_indexes)

        for idx, ltr in enumerate(ring):
            # print(idx, ltr)
            ltr_indexes.setdefault(ltr, []).append(idx)

        # print(ltr_indexes)

        ln = len(ring)
        l_lens = [0] * ln

        prev_ltr = '#'
        for ltr in key:
            for pos in ltr_indexes[ltr]:
                # print(pos, "   ", ltr)
                all_variants = []

                for prev_pos in ltr_indexes[prev_ltr]:  
                    clk_w = abs(prev_pos - pos) 
                    a_clk = ln - clk_w 
                    all_variants.append(min(clk_w, a_clk) + l_lens[prev_pos])

                # print(all_variants)

                l_lens[pos] = min(all_variants)

                # print(l_lens)

            prev_ltr = ltr

        # print(ltr_indexes)

        min_len = 9 * 100000

        for pos in ltr_indexes[prev_ltr]:
            min_len = min(min_len, l_lens[pos])

        return min_len + len(key)

        # return min(l_lens[pos] for pos in ltr_indexes[ltr]) + len(key)


x = Solution()
print(x.findRotateSteps("godding", "godding"))
