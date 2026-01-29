#字符串重排序 791. Custom Sort String
class Solution:
    def reorder_string(self, order: str, s: str):
        order_index = {ch: i for i, ch in enumerate(s)}
        return ''.join(sorted(order, key=lambda x: order_index.get(x,float('inf'))))

def main(): 

    s = 'adc'
    order = 'bacd'

    solution = Solution()
    result = solution.reorder_string(order, s)

    print(result)

if __name__ == "__main__":
    main()


