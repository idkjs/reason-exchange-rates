open BsReactNative;
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();
let httpLink =
  ApolloLinks.createHttpLink(
    ~uri="https://48p1r2roz4.sse.codesandbox.io",
    (),
  );
let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());
let app = () =>
  <ApolloProvider client=instance>
    <View style=Styles.styles##container> <ExchangeRateView /> </View>
  </ApolloProvider>;
