# Turtle-like Spherical Amphibious Quadruped Robot

A bio-inspired amphibious robot that walks on land and swims underwater — with a turtle-like spherical shell for protection, 12 servo-driven legs, and 4 foot-integrated propellers for float/sink control and obstacle avoidance.

**Awards:** 2nd Place, Virginia Piedmont Regional Science Fair (VPRSF) · Booz Allen Award for Innovativeness

![Robot main body with labeled components](docs/paper-figures/image55.png)

## Overview

Most amphibious robots can't control their own floating and sinking — they rely on legs or rolling, can't swim fast, and struggle on uneven terrain. This project combines a **spherical robot** (protection + maneuverability, like a turtle retracting into its shell) with a **legged robot** (all-terrain walking), plus an integrated **leg-propeller lower body** so the robot can adjust leg angles and use propeller thrust to float, sink, and avoid underwater obstacles.

Key differences from conventional designs:
1. **Servo-driven legs** — 12 servos let the robot perform many distinct actions through joint-angle control, greatly improving environmental adaptability.
2. **Leg-propeller integration** — propellers built into the feet; by adjusting leg angles the robot controls its depth underwater for obstacle avoidance, and propeller propulsion is far more efficient than paddling (2× speed in testing).
3. **Cheap, accessible materials** — plastic shell, acrylic plates, 3D-printed parts, off-the-shelf electronics.

## System Design

### Mechanical
- **Shell:** plastic dome cover (metal was too expensive) for water isolation and impact protection
- **Connection ring:** 3D-printed, with a ravine on top so the shell fits; 6× 4 mm screw holes, rounded corners to prevent breakage
- **Fixed plates:** two layers / three acrylic sheets (5 mm) supporting the body; hole positions iterated through 4 draft revisions
- **Legs:** 12× DS3218 servos (3 per leg, ~90° range of motion); 2nd-gen feet are 3D-printed with integrated propellers
- **Waterproofing:** waterproof glue + hot melt adhesive on all seams, waterproof nuts on wire holes, waterproof tape on servo wires, plus an inner sponge layer as a last line of defense (validated with a 10-minute submersion test)

### Electronics
| Component | Role |
|---|---|
| Arduino control board | Main controller |
| 2× 16-way servo driver boards | Drive the 12 leg servos (serial protocol) |
| 2× L298N motor driver modules | Drive the 4 underwater propellers |
| Buck (step-down) module | Power regulation |
| Bluetooth module (Blinker BLE) | Receives commands from the phone app |
| Lithium battery (XT60) | Power supply |

Two servo driver boards were needed because a single board couldn't supply enough current for all 12 servos under load — this was the fix after the legs couldn't support the body in early testing.

### Software — `firmware/Turtle_final.ino`
- **App control:** the robot is driven from the Blinker app over Bluetooth. Each button sets a `task` variable; `loop()` dispatches to the corresponding motion function.
- **Gaits:** `TurtleForward` / `TurtleBackward` / `TurtleSpinCW` / `TurtleSpinCCW` implement a turtle-inspired quadruped gait with per-step servo timing (Chinese comments in code describe each leg movement).
- **Swim modes:** `TurtleSwimForward` / `TurtleSwimLeft` / `TurtleSwimUP` / `TurtleSwimDOWN` combine servo poses with propeller thrust.
- **Servo tuning:** send `pin` then `value` over USB serial to adjust any servo angle live — used to calibrate every pose in the code.

#### App button mapping
| Button | Action |
|---|---|
| btn-1 | Walk forward (land) |
| btn-2 | Walk backward (land) |
| btn-3 | Swim left |
| btn-5 | Swim forward |
| btn-7 | Stand / reset pose |
| btn-8 | Spin clockwise (land) |
| btn-9 | Spin counter-clockwise (land) |
| btn-10 | Emergency stop (all motors off) |

Note: btn-4 / btn-6 are unbound in this version; float-up / sink-down are implemented (`TurtleSwimUP`/`TurtleSwimDOWN`) but not yet mapped to buttons. Control app: Blinker (reinstall from app store; recreate the device and re-bind the 10 buttons if the original device key is lost).

## Experiments

**Land speed** (40 cm robot, 200 cm carpet):
- First test: 60 cm in 11 s → 5.45 cm/s (**0.14 BL/s**) — far below target. Causes: robot too heavy for available current; gait cycle too slow (~4 s per cycle).
- After boosting voltage + improving gait: 215 cm in 18 s → 12 cm/s (**0.30 BL/s**, 0.34 BL/s excluding a 2 s turn) — much better, still below the 0.5 BL/s goal.

**Water speed** (218 × 109 cm tank):
- Propeller swimming: 200 cm in 8 s → 25 cm/s (**0.625 BL/s**)
- Paddling (leg gait in water): 180 cm in 20 s → 9 cm/s (**0.225 BL/s**)
- → Propeller propulsion roughly **doubles** underwater speed vs. paddling.

![Water test: swimming trials](docs/paper-figures/image73.png)

**Float test:** the robot only rose ~2 cm at full upward thrust. Root causes found: the robot's weight vs. propeller thrust — under full load each motor draws 0.5 A but the battery maxes at 1 A, so propellers stalled underwater. Planned fixes: higher-current buck module, more batteries, and counterweight blocks for neutral buoyancy.

**Kinematic model:** step distance `d = 2L·sinθ`, velocity `V = 2fL·sinθ` (f = step frequency) — speed can be raised via stride angle or step frequency.

## Limitations & Future Work
- Land speed (0.3 BL/s) and float range (2 cm) are limited by weight vs. power — the core tradeoff to solve next.
- The sealed shell can't be reopened to swap batteries or flip the power switch (design oversight); a future revision needs a serviceable hatch or wireless charging.
- Next steps: better gait tuning, spring-loaded feet for jumping, onboard sensors for stable teleoperation, and eventually a larger all-terrain platform.

## Repo Structure
```
turtle-amphibious-robot/
├── README.md
├── firmware/
│   └── Turtle_final.ino      # Arduino firmware (Blinker BLE + gait/swim control)
└── docs/
    └── paper-figures/        # 59 figures extracted from the project paper
```

## Paper
Full project paper (ISEF-style, 42 pages with all design figures and experiment data): available on request.
