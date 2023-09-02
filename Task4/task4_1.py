class Villain:
    def __init__(self, name, health=100, energy=500, shield=0):
        self.name = name
        self.health = health
        self.energy = energy
        self.shield = shield

    def take_damage(self, damage):
        if self.shield > 0:
            reduction_percentage = self.shield / 100
            damage -= int(damage * reduction_percentage)
        self.health -= damage

    def use_energy(self, energy):
        self.energy -= energy

class Gru(Villain):
    def __init__(self):
        super().__init__("Gru")
        self.resources = {
            "Freeze Gun": float('inf'),
            "Electric Prod": 5,
            "Mega Magnet": 3,
            "Kalman Missile": 1,
            "Energy-Projected BarrierGun":float('inf'),                          
            "elective Permeability":2
        }

    def attack(self, opponent, weapon):
        if weapon == 1:
            opponent.take_damage(11)
            self.use_energy(50)
        elif weapon == 2:
            opponent.take_damage(18)
            self.use_energy(88)
            self.resources["Electric Prod"] -= 1
        elif weapon == 3:
            opponent.take_damage(10)
            opponent.apply_shield(20)
            self.use_energy(92)
            self.resources["Mega Magnet"] -= 1
        elif weapon == 4:
            opponent.take_damage(20)
            self.use_energy(120)
            self.resources["Kalman Missile"] -= 1

    def defend(self, shield):
        if shield == 1:
            self.shield = 40
            self.use_energy(20)
        elif shield == 2:
            self.shield = 90
            self.use_energy(50)
            self.resources["Selective Permeability"] -= 1

class Vector(Villain):
    def __init__(self):
        super().__init__("Vector")
        self.resources = {
            "Laser Blasters": 10000,
            "Plasma Grenades": 8,
            "Sonic Resonance Cannon": 3,
            "energy Net Trap":10000,
            "Quantum Deflector":3
        }

    def attack(self, opponent, weapon):
        if weapon == 1:
            opponent.take_damage(8)
            self.use_energy(40)
        elif weapon == 2:
            opponent.take_damage(13)
            self.use_energy(56)
            self.resources["Plasma Grenades"] -= 1
        elif weapon == 3:
            opponent.take_damage(22)
            self.use_energy(100)
            self.resources["Sonic Resonance Cannon"] -= 1

    def defend(self, shield):
        if shield == 1:
            self.shield = 32
            self.use_energy(15)
        elif shield == 2:
            self.shield = 80
            self.use_energy(40)
            self.resources["Quantum Deflector"] -= 1

# The begining of the Battle  
gru = Gru()
vector = Vector()

rounds = 0
gru_shield = None
vector_shield = None
while gru.health > 0 and vector.health > 0:
    rounds += 1
    print(f"Round {rounds}:")
    print(f"              Gru ")
    print(f"health: {gru.health}   &&   energy: {gru.energy}")
    print(f"              Vector")
    print(f"health: {vector.health}  &&    energy: {vector.energy}")

    gru_action = None
    while gru_action not in [1, 2]:
        try:
            gru_action = int(input("\nGru's Choose \n1. for attack\n2. for defend\n\t: "))
        except ValueError:
            print("Invalid input. Please enter a number.")
    if gru_action == 1:
        print("Choose Gru's weapon:")
        print("1. Freeze Gun")
        print("2. Electric Prod")
        print("3. Mega Magnet")
        print("4. Kalman Missile")
        gru_weapon = int(input("Enter the number of the weapon: "))
        if gru_weapon in range(1, 5):
            weapon = list(gru.resources.keys())[gru_weapon - 1]
            if gru.resources[weapon] > 0:
                gru.attack(vector, gru_weapon)
                gru.resources[weapon] -= 1
            else:
                print("You don't have enough resources to use this weapon.")
        else:
            print("Invalid weapon choice.")
    elif gru_action == 2:
        print("Choose Gru's shield:")
        print("1. Energy-Projected BarrierGun")
        print("2. Selective Permeability")
        gru_shield = int(input("Enter the number of the shield: "))
        if gru_shield in range(1, 3):
            gru.defend(gru_shield)
        else:
            print("Invalid shield choice.")

    vector_action = None
    while vector_action not in [1, 2]:
        try:
            vector_action = int(input("\nvector's Choose \n1. for attack\n2. for defend\n\t: "))
        except ValueError:
            print("Invalid input. Please enter a number.")
    if vector_action == 1:
        print("Choose vector's weapon:")
        print("1. Laser Blasters")
        print("2. Plasma Grenades")
        print("3. Sonic Resonance Cannon")
        vector_weapon = int(input("Enter the number of the weapon: "))
        if vector_weapon in range(1, 4):
            weapon = list(vector.resources.keys())[vector_weapon - 1]
            if vector.resources[weapon] > 0:
                vector.attack(gru, vector_weapon)
                vector.resources[weapon] -= 1
            else:
                print("You don't have enough resources to use this weapon.")
        else:
            print("Invalid weapon choice.")
    elif vector_action == 2:
        print("Choose vector's shield:")
        print("1. Energy Net Trap")
        print("2. Quantum Deflector")
        vector_shield = int(input("Enter the number of the shield: "))
        if vector_shield in range(1, 3):
            vector.defend(vector_shield)
        else:
            print("Invalid shield choice.")

    print(f"Gru's shield: {gru.shield}%")
    print(f"Vector's shield: {vector.shield}%")

print("Game over!")
if gru.health <= 0:
    print("Vector wins!")
else:
    print("Gru wins!")