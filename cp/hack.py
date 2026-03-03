import random
N = 200000 

def main():
    print(1) 
    
    print(f"{N} 1 1 1000000000 1000000000")
    
    PRIME = 393241
    
    x_coords = []
    for i in range(1, N + 1):
        x_coords.append(i * PRIME)
        
    print(*(x_coords))
    
    print(*(random.randint(1, 1000000000) for _ in range(N)))

if __name__ == "__main__":
    main()