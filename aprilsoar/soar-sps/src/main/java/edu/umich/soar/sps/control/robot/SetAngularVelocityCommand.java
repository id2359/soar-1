/**
 * 
 */
package edu.umich.soar.sps.control.robot;

import org.apache.log4j.Logger;

import sml.Identifier;

/**
 * @author voigtjr
 *
 * Set linear and angular velocities.
 * 
 * Returns executing. Not interruptable. Creates DDC.
 */
final public class SetAngularVelocityCommand extends DDCCommand implements Command {
	private static final Logger logger = Logger.getLogger(SetAngularVelocityCommand.class);
	private static final String ANGVEL = "angular-velocity";
	static final String NAME = "set-angular-velocity";

	static Command newInstance() {
		return new SetAngularVelocityCommand();
	}
	
	private double angularVelocity;

	private SetAngularVelocityCommand() {
	}

	@Override
	public DifferentialDriveCommand getDDC() {
		return DifferentialDriveCommand.newAngularVelocityCommand(angularVelocity);
	}

	@Override
	public boolean execute(Identifier command) {
		if (this.command != null) {
			throw new IllegalStateException();
		}
		
		try {
			angularVelocity = Math.toRadians(Double.parseDouble(command.GetParameterValue(ANGVEL)));
		} catch (NullPointerException ex) {
			CommandStatus.error.addStatus(command, NAME + ": No " + ANGVEL + " on command");
			return false;
		} catch (NumberFormatException e) {
			CommandStatus.error.addStatus(command, NAME + ": Unable to parse " + ANGVEL + ": " + command.GetParameterValue(ANGVEL));
			return false;
		}

		logger.debug(String.format(NAME + ": a%3.1f", angularVelocity));
		CommandStatus.accepted.addStatus(command);
		CommandStatus.executing.addStatus(command);
		
		this.command = command;
		return true;
	}
}
