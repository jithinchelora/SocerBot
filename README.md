# Soccer Bot Workshop

A 2-day, 6-hour robotics workshop for 8th graders and above. Students build a radio-controlled two-wheeled robot, learn to drive it, and play a soccer match on day two. Kits go home with the team.

## What students build

A differential-drive robot with a claw-shaped front for trapping and pushing a ball.

- **Brain:** Arduino Uno
- **Drive:** 2× BO motors with rubber wheels, 1× castor wheel
- **Motor driver:** L298N H-bridge
- **Radio:** FlySky FS-GT2 transmitter + FS-GR3E receiver (2 channels, car-style)
- **Power:** 2× 18650 Li-ion cells in series (~7.4V)
- **Chassis:** Acrylic or foam-board base with claw front and castor mount or powder coated aluminium

## Repo layout

```
code/             Arduino sketches — main + test sketches
docs/             Wiring, BOM, flowchart
workshop/         Facilitator guide, student handout, troubleshooting
```

## Quick start (for facilitators)

1. Read `workshop/facilitator_guide.md` end-to-end before the workshop.
2. Pre-flash all Arduinos with `code/test_sketches/motor_test.ino` to verify hardware on arrival.
3. On day 2, students flash `code/soccer_bot/soccer_bot.ino`.
4. Use `workshop/troubleshooting.md` when something inevitably goes wrong.

## Quick start (for students)

1. Day 1: assemble the chassis, wire the motors and receiver.
2. Day 2: upload the code, calibrate, play.
3. Take the kit home and break it. Then fix it. That's the actual lesson.

## License

MIT. Use it, fork it, run your own workshop. A credit back is appreciated but not required.
