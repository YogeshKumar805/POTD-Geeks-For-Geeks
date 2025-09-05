class Solution {
  segregate(head) {
    let initAns = [];
    let news = head;
    while (news) {
      initAns.push(news.data);
      news = news.next;
    }

    const reducedValue = initAns.sort((a, b) => a - b);
    let current = head;
    let cou = 0;
    while (current) {
      current.data = reducedValue[cou];
      cou += 1;
      current = current.next;
    }

    return head;
  }
}
