class Solution:

    def isBalanced(self, s):

        # code here

        n = len(s)

        stack = []

        for i in range(n):

            curr = s[i]

            if curr == '(' or curr == '{' or curr == '[':

                stack.append(curr)

            else:

                if not stack:

                    return False

                else:

                    top = stack[-1]

                    stack.pop()

                    if (curr == ')' and top != '(') or (curr == '}' and top != '{') or (curr == ']' and top != '['):

                        return False

        return True if len(stack) == 0 else False
