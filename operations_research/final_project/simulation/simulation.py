from epyt import epanet
import numpy as np
import matplotlib.pyplot as plt
import os

def simulate_attack(network, attack_node, concentration, start_time, duration):
    """Simulates a contaminant attack on the water network"""
    # Set up quality analysis for chemical contaminant
    network.setQualityType('CHEM', 'Contaminant', 'mg/L')
    
    # Create pattern for timed injection (1 during attack, 0 otherwise)
    pattern_values = np.zeros(24)  # 24-hour simulation
    pattern_values[start_time:start_time+duration] = 1.0
    
    # Add injection pattern and set the contaminant source
    pattern_id = f"Attack_{attack_node}"
    try:
        network.addPattern(pattern_id, pattern_values)
    except:
        pattern_index = network.getPatternIndex(pattern_id)
        network.setPattern(pattern_index, pattern_values)
    
    pattern_index = network.getPatternIndex(pattern_id)
    node_index = network.getNodeIndex(attack_node)
    
    # Set the contaminant source
    network.setNodeSourceType(node_index, "SETPOINT")
    network.setNodeSourceQuality(node_index, concentration)
    network.setNodeSourcePatternIndex(node_index, pattern_index)
    
    # Run quality simulation and return results
    return network.getComputedQualityTimeSeries()

def analyze_results(network, results, attack_info, output_dir):
    """Analyzes and visualizes contamination spread"""
    os.makedirs(output_dir, exist_ok=True)
    
    # Extract quality data
    times = results.Time
    node_quality = results.NodeQuality
    
    # Calculate affected nodes (above 0.01 mg/L threshold)
    threshold = 0.01
    affected_nodes = np.sum(np.max(node_quality, axis=0) > threshold)
    total_nodes = network.getNodeCount()
    affected_percentage = (affected_nodes / total_nodes) * 100
    
    # Create network plot of maximum concentrations
    plt.figure(figsize=(10, 8))
    max_conc = np.max(node_quality, axis=0)
    network.plot(node_values=max_conc, 
                 title=f"Attack at {attack_info['node']} - Maximum Contaminant Concentration",
                 colorbar_label="Concentration (mg/L)")
    plt.savefig(f"{output_dir}/attack_{attack_info['node']}_spatial.png", dpi=300)
    
    # Plot contamination over time for most affected nodes
    most_affected = np.argsort(np.max(node_quality, axis=0))[-5:]  # Top 5 affected nodes
    plt.figure(figsize=(12, 6))
    for node_idx in most_affected:
        node_id = network.getNodeNameID(node_idx + 1)
        plt.plot(times, node_quality[:, node_idx], label=f"Node {node_id}")
    
    plt.xlabel("Time (hours)")
    plt.ylabel("Concentration (mg/L)")
    plt.title(f"Attack at {attack_info['node']} - Contaminant Spread")
    plt.grid(True)
    plt.legend()
    plt.savefig(f"{output_dir}/attack_{attack_info['node']}_timeseries.png", dpi=300)
    
    return {
        "affected_nodes": affected_nodes,
        "affected_percentage": affected_percentage,
        "max_concentration": np.max(node_quality)
    }

# Main execution
if __name__ == "__main__":
    # Create output directory
    output_dir = "attack_results"
    os.makedirs(output_dir, exist_ok=True)
    
    # Define attack scenarios
    scenarios = [
        {"node": "101", "name": "High-Demand Junction", "concentration": 100, "start_time": 0, "duration": 3},
        {"node": "10", "name": "Lake Pump Outlet", "concentration": 100, "start_time": 1, "duration": 2},
        {"node": "121", "name": "Central Junction", "concentration": 100, "start_time": 6, "duration": 4},
        {"node": "151", "name": "Long Duration", "concentration": 20, "start_time": 0, "duration": 12}
    ]
    
    # Run scenarios and collect results
    scenario_results = []
    
    for scenario in scenarios:
        print(f"Simulating attack at node {scenario['node']} ({scenario['name']})")
        
        # Load fresh network for each scenario
        net = epanet("net3.inp")
        
        # Run simulation
        results = simulate_attack(
            net, 
            scenario['node'],
            scenario['concentration'],
            scenario['start_time'],
            scenario['duration']
        )
        
        # Analyze results
        analysis = analyze_results(net, results, scenario, output_dir)
        scenario_results.append({**scenario, **analysis})
        
        # Clean up
        net.unload()
    
    # Print summary of results
    print("\nAttack Scenario Summary:")
    print("------------------------")
    for result in scenario_results:
        print(f"Attack at {result['node']} ({result['name']}):")
        print(f"  - Affected {result['affected_nodes']} nodes ({result['affected_percentage']:.1f}% of network)")
        print(f"  - Maximum concentration: {result['max_concentration']:.2f} mg/L")
        print()