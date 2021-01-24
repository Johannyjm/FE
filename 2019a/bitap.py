mask = [0] * 26

def idx(c):
    return ord(c) - ord('A')

def generate_bitmask(pat):
    pat_len = len(pat)
    for i in range(26):
        mask[i] = 0
    
    for i in range(pat_len):
        mask[idx(pat[i])] = (1<<i) | mask[idx(pat[i])]
    
    return pat_len

def bitap_match(text, pat):
    text_len = len(text)
    pat_len = generate_bitmask(pat)

    status = 0
    goal = (1<<(pat_len-1))
    for i in range(text_len):
        status = ((status << 1) | (1))
        status = status & mask[idx(text[i])]

        if(status & goal != 0):
            return (i - pat_len + 2)

    return -1

def main():
    text = input()
    pat = input()

    print(bitap_match(text, pat))


if __name__ == "__main__":
    main()
