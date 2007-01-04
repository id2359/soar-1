package soar2d.player;

import soar2d.Direction;
import soar2d.Soar2D;
import soar2d.World;

public class Tank extends Player {
	/**
	 * missile count
	 */
	protected int missiles;
	/**
	 * energy count
	 */
	protected int energy;
	/**
	 * health count
	 */
	protected int health;
	/**
	 * true if shields up
	 */
	protected boolean shieldsUp;
	/**
	 * radar switch
	 */
	protected boolean radarSwitch;
	/**
	 * radar power setting
	 */
	protected int radarPower;
	
	protected int observedPower;

	RadarCell[][] radar = new RadarCell[Soar2D.config.kRadarWidth][Soar2D.config.kRadarHeight];
	
	protected int rwaves;
	protected int blocked;
	protected int incoming;
	
	MoveInfo move;

	public Tank( PlayerConfig playerConfig) {
		super(playerConfig);
		
		reset();
	}
	
	public boolean getRadarSwitch() {
		return radarSwitch;
	}
	
	public RadarCell[][] getRadar() {
		return radar;
	}
	
	public int getObservedDistance() {
		return observedPower;
	}
	
	public void setRadarSwitch(boolean setting) {
		if (radarSwitch == setting ) {
			return;
		}
		radarSwitch = setting;
		logger.info(getName() + " radar switched " + (setting ? "on" : "off"));
	}
	
	public int getRadarPower() {
		return radarPower;
	}
	
	public void setRadarPower(int setting) {
		if (setting < 0) {
			setting = 0;
		}
		if (setting >= Soar2D.config.kRadarHeight) {
			setting = Soar2D.config.kRadarHeight - 1;
		}
		if (radarPower == setting) {
			return;
		}
		radarPower = setting;
		logger.info(getName() + " radar power set to: " + Integer.toString(this.radarPower));
	}
	
	public int getMissiles() {
		return missiles;
	}
	/**
	 * @param missiles the new missile count
	 * @param comment why the change happened, keep it very brief
	 * 
	 * set the missiles to a specific value, the comment goes in the log
	 */
	public void setMissiles(int missiles, String comment) {
		this.missiles = missiles;
		if (comment != null) {
			logger.info(getName() + " missiles set to: " + Integer.toString(this.missiles) + " (" + comment + ")");
		} else {
			logger.info(getName() + " missiles set to: " + Integer.toString(this.missiles));
		}
	}
	/**
	 * @param delta the change in missiles
	 * @param comment why the change happened, keep it very brief
	 * 
	 * this is a handy function for changing missiles. puts a message in the log and 
	 * why the change happened
	 */
	public void adjustMissiles(int delta, String comment) {
		int previous = this.missiles;
		this.missiles += delta;
		if (missiles < 0) {
			logger.warning(getName() + ": missiles adjusted to negative value");
			missiles = 0;
		}
		if (missiles == previous) {
			return;
		}
		if (comment != null) {
			logger.info(getName() + " missiles: " + Integer.toString(previous) + " -> " + Integer.toString(this.missiles) + " (" + comment + ")");
		} else {
			logger.info(getName() + " missiles: " + Integer.toString(previous) + " -> " + Integer.toString(this.missiles));
		}
	}

	public int getEnergy() {
		return energy;
	}
	/**
	 * @param energy the new energy count
	 * @param comment why the change happened, keep it very brief
	 * 
	 * set the energy to a specific value, the comment goes in the log
	 */
	public void setEnergy(int energy, String comment) {
		// Bring down shields if out of energy

		this.energy = energy;
		if (comment != null) {
			logger.info(getName() + " energy set to: " + Integer.toString(this.energy) + " (" + comment + ")");
		} else {
			logger.info(getName() + " energy set to: " + Integer.toString(this.energy));
		}
	}
	/**
	 * @param delta the change in energy
	 * @param comment why the change happened, keep it very brief
	 * 
	 * this is a handy function for changing energy. puts a message in the log and 
	 * why the change happened
	 */
	public void adjustEnergy(int delta, String comment) {
		// Bring down shields if out of energy

		int previous = this.energy;
		this.energy += delta;
		if (energy < 0) {
			energy = 0;
		}
		if (energy > Soar2D.config.kDefaultEnergy) {
			energy = Soar2D.config.kDefaultEnergy;
		}
		if (energy == previous) {
			return;
		}
		if (comment != null) {
			logger.info(getName() + " energy: " + Integer.toString(previous) + " -> " + Integer.toString(this.energy) + " (" + comment + ")");
		} else {
			logger.info(getName() + " energy: " + Integer.toString(previous) + " -> " + Integer.toString(this.energy));
		}
	}

	public int getHealth() {
		return health;
	}
	/**
	 * @param health the new missile count
	 * @param comment why the change happened, keep it very brief
	 * 
	 * set the health to a specific value, the comment goes in the log
	 */
	public void setHealth(int health, String comment) {
		this.health = health;
		if (comment != null) {
			logger.info(getName() + " health set to: " + Integer.toString(this.health) + " (" + comment + ")");
		} else {
			logger.info(getName() + " health set to: " + Integer.toString(this.health));
		}
	}
	/**
	 * @param delta the change in health
	 * @param comment why the change happened, keep it very brief
	 * 
	 * this is a handy function for changing health. puts a message in the log and 
	 * why the change happened
	 */
	public void adjustHealth(int delta, String comment) {
		int previous = this.health;
		this.health += delta;
		if (health < 0) {
			health = 0;
		}
		if (health > Soar2D.config.kDefaultHealth) {
			health = Soar2D.config.kDefaultHealth;
		}
		if (health == previous) {
			return;
		}
		if (comment != null) {
			logger.info(getName() + " health: " + Integer.toString(previous) + " -> " + Integer.toString(this.health) + " (" + comment + ")");
		} else {
			logger.info(getName() + " health: " + Integer.toString(previous) + " -> " + Integer.toString(this.health));
		}
	}
	
	public boolean shieldsUp() {
		return shieldsUp;
	}

	public void update(World world, java.awt.Point location) {
		moved = (location.x != this.previousLocation.x) || (location.y != this.previousLocation.y);
		
		if (radarSwitch) {
			observedPower = world.map.getRadar(radar, location, getFacingInt(), radarPower);
		}
		
		blocked = world.map.getBlocked(location);
	}
	
	public int getBlocked() {
		return blocked;
	}
	
	public int getIncoming() {
		System.out.println(getName() + ": incoming reported " + incoming);
		return incoming;
	}
	
	public boolean getHumanMove() {
		if (Soar2D.config.graphical == false) {
			move = new MoveInfo();
			return true;
		}
		
		move = Soar2D.wm.getHumanMove(this.getColor());

		if (move == null) {
			return false;
		}
		
		return true;
	}

	public MoveInfo getMove() {
		resetSensors();
		
		return move;
	}
	
	public void reset() {
		super.reset();
		
		if (playerConfig.hasMissiles()) {
			this.missiles = playerConfig.getMissiles();
		} else {
			this.missiles = Soar2D.config.kDefaultMissiles;
		}
		if (playerConfig.hasHealth()) {
			this.health = playerConfig.getHealth();
		} else {
			this.health = Soar2D.config.kDefaultHealth;
		}
		if (playerConfig.hasEnergy()) {
			this.energy = playerConfig.getEnergy();
		} else {
			this.energy = Soar2D.config.kDefaultEnergy;
		}
		
		shieldsUp = false;
	}
	
	public void setShields(boolean setting) {
		if (shieldsUp == setting) {
			return;
		}
		logger.info(getName() + " shields switched " + (setting ? "on" : "off"));
		shieldsUp = setting;
	}
	
	public void radarTouch(int fromDirection) {
		rwaves |= Direction.indicators[fromDirection];
	}
	
	public void setIncoming(int fromDirection) {
		incoming |= Direction.indicators[fromDirection];
		System.out.println(getName() + ": incoming set " + incoming);
	}
	public int getRWaves() {
		return rwaves;
	}

	public void resetSensors() {
		rwaves = 0;
		incoming = 0;
		blocked = 0;
	}

	public void shutdown() {
		
	}
}
