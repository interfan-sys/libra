
from typing import Optional, Tuple, List


class Zone:
    """Represent a zone in the drone graph.

    A zone is a location that drones can occupy and move through.
    It has a position in the graph, a type that determines its
    movement behavior, and a capacity that limits the number of
    drones it can contain.
    """
    def __init__(
            self,
            name: str,
            coordinates: Tuple[int, int],
            zone_type: str,
            color: Optional[str],
            max_drones: int
    ) -> None:
        """Initialize a zone.

        Args:
            name: Unique name of the zone.
            coordinates: X and Y coordinates of the zone.
            zone_type: Type of zone, such as normal, restricted,
            priority, or blocked.
            color: Optional color used for graphical visualization.
            max_drones: Maximum number of drones allowed in the zone.
        """
        self.name = name
        self.coordinates = coordinates
        self.zone_type = zone_type
        self.color = color
        self.max_drones = max_drones


class Connection:
    """Represent a bidirectional connection between two zones.

    A connection defines a path that drones can use to move
    between two zones. It also stores the maximum number of
    drones that can use the connection at the same time.
    """
    def __init__(
            self,
            zone1: Zone,
            zone2: Zone,
            max_link_capacity: int
    ) -> None:
        """Initialize a connection between two zones.

        Args:
            zone1: The first zone connected by the connection.
            zone2: The second zone connected by the connection.
            max_link_capacity: Maximum number of drones allowed
            on the connection at the same time.
        """
        self.zone1 = zone1
        self.zone2 = zone2
        self.max_link_capacity = max_link_capacity


class Drone:
    """Represents a drone moving through the graph.

    A drone has a unique identifier and a current position
    """
    def __init__(self, drone_id: int, current_zone: Zone) -> None:
        """Initialize a drone.
        Args:
            drone_id: Unique identifier of the drone.
            current_zone: Zone object representing drone's
                current location.
        """
        self.drone_id = drone_id
        self.current_zone = current_zone


class Graph:
    """Represent the graph of zones and connections.

    The graph stores all zones, connections, and the start and
    end zones used by the simulation.
    """
    def __init__(
            self,
            zones: List[Zone],
            connections: List[Connection],
            start_hub: Zone,
            end_hub: Zone
    ) -> None:
        """Initialize the graph.
        Args:
            zones: List of zone objects in the graph.
            connections: List of connection objects between zones.
            start_zone: Zone where all drones start.
            end_zone: Zone where drones must arrive.
        """
        self.zones = zones
        self.connections = connections
        self.start_hub = start_hub
        self.end_hub = end_hub
