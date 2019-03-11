import {AppRegistry} from 'react-native';
import {app as App} from './Main.bs';

AppRegistry.registerComponent("App", () => App);
AppRegistry.runApplication("App", { rootTag: document.getElementById("root") });
