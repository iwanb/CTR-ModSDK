"""Script to generate the weapon RNG arrays."""
from pathlib import Path

turbo = 0
bomb = 1
missile = 2
tnt = 3
potion = 4
spring = 5  # unusable
shield = 6
mask = 7
clock = 8
warpball = 9
triple_bomb = 10
triple_missile = 11
no_weapon = 15  # Can be used to have empty boxes

def make_weaponset(size: int, weapons):
    byte_array = []
    for amount, weapon in weapons:
        byte_array.extend(amount * [weapon])
    if len(byte_array) != size:
        raise ValueError(f"The weapon set is of size {size} but you gave {len(byte_array)} weapons")
    return bytes(byte_array)

def weaponset_race1(*weapons):
    return make_weaponset(20, weapons)

def weaponset_race2(*weapons):
    return make_weaponset(52, weapons)

def weaponset_race3(*weapons):
    return make_weaponset(20, weapons)

def weaponset_race4(*weapons):
    return make_weaponset(20, weapons)

def weaponset_bossrace(*weapons):
    return make_weaponset(20, weapons)

default_race1 = weaponset_race1(
    (8, potion),
	(8, tnt),
    (2, bomb),
	(1, turbo),
	(1, shield),
)
default_race2 = weaponset_race2(
    (10, potion),
    (8, tnt),
    (5, bomb),
    (3, triple_bomb),
    (5, turbo),
    (3, shield),
    (3, missile),
    (2, triple_missile),
    (5, warpball),
    (7, mask),
    (1, clock),
)
default_race3 = weaponset_race3(
	(1, potion),
    (1, tnt),
    (1, bomb),
    (2, triple_bomb),
    (2, turbo),
    (1, shield),
    (2, missile),
    (1, triple_missile),
    (3, warpball),
    (5, mask),
    (1, clock),
)
default_race4 = weaponset_race4(
    (1, turbo),
    (1, shield),
    (1, missile),
    (1, triple_missile),
    (5, warpball),
    (8, mask),
    (2, clock),
    (1, turbo),
)
default_bossrace = weaponset_bossrace(
    (1, potion),
    (1, tnt),
    (1, bomb),
    (2, triple_bomb),
    (2, turbo),
    (1, shield),
    (1, missile),
    (1, triple_missile),
    (3, warpball),
    (5, mask),
    (2, clock),
)

def overwrite_weapons(
    # 1st in all race modes
    race1=default_race1,
    # 2nd place with 4 players
    # or 2nd or 3rd place with 6 players
    # or 3rd or 4th place with 8 players
    race2=default_race2,
    race3=default_race3,
    race4=default_race4,
    # 2nd place with 2 players
    bossrace=default_bossrace,
):
    full_array = race1 + race2 + race3 + race4 + bossrace
    (Path(__file__).parent / 'assets' / 'weapons.bin').write_bytes(
        full_array
    )

overwrite_weapons(
    # Give triple bomb too
    race1=weaponset_race1(
        (8, potion),
        (8, tnt),
        (1, bomb),
        (1, triple_bomb),
        (1, turbo),
        (1, shield),
    ),
    # Remove the clock and triple missiles
    # More potion, less mask
    bossrace=weaponset_bossrace(
        (2, potion),
        (1, tnt),
        (1, bomb),
        (2, triple_bomb),
        (2, turbo),
        (1, shield),
        (2, missile),
        (3, warpball),
        (4, mask),
        (2, turbo),
    )
)
